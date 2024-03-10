/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** attack_player
*/
#include "myrpg.h"

static int horizontal_range(boss_t *nemesis, player_t *player)
{
    if (player->direction == DOWN)
        if ((nemesis->coord.y > player->coord.y)
        && (nemesis->coord.y < (player->coord.y + 70))
        && (nemesis->coord.x > player->coord.x - 100)
        && (nemesis->coord.x < player->coord.x + 100))
            return 0;
    if (player->direction == UP)
        if ((nemesis->coord.y < player->coord.y)
        && nemesis->coord.y > (player->coord.y - 170)
        && (nemesis->coord.x > player->coord.x - 100)
        && (nemesis->coord.x < player->coord.x + 100))
            return 0;
    return 1;
}

static int attack_range_player(boss_t *nemesis, player_t *player)
{
    if (horizontal_range(nemesis, player) == 0)
        return 0;
    if (player->direction == LEFT)
        if ((nemesis->coord.x < player->coord.x)
        && nemesis->coord.x > (player->coord.x - 180)
        && (nemesis->coord.y > player->coord.y - 100)
        && (nemesis->coord.y < player->coord.y + 100))
            return 0;
    if (player->direction == RIGHT)
        if ((nemesis->coord.x > player->coord.x)
        && nemesis->coord.x < (player->coord.x + 117)
        && (nemesis->coord.y > player->coord.y - 100)
        && (nemesis->coord.y < player->coord.y + 100))
            return 0;
    return 1;
}

static boss_t *check_attack(boss_t *nemesis, player_t *player)
{
    if (attack_range_player(nemesis, player) == 0 && nemesis->state != DEAD) {
        touched_nemesis(nemesis, player);
        launch_jumpjo(nemesis);
    }
    return nemesis;
}

boss_t *detect_attack_player_nemesis(boss_t *nemesis, player_t *player)
{
    if (player->state == ATTACKING && player->rect.left == 384)
        check_attack(nemesis, player);
    return nemesis;
}

player_t *attack_player_nemesis(player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        player->state = ATTACKING;
        player->rect.left = 0;
        if (player->direction == DOWN)
            player->rect.top = 1536;
        if (player->direction == UP)
            player->rect.top = 1728;
        if (player->direction == LEFT)
            player->rect.top = 1920;
        if (player->direction == RIGHT)
            player->rect.top = 2112;
        sfSprite_setTextureRect(player->sprite, player->rect);
    }
    return player;
}

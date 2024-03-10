/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** attack_player
*/
#include "myrpg.h"

static int horizontal_range(enemy_t *enemy, player_t *player)
{
    if (player->direction == DOWN)
        if ((enemy->coord.y > player->coord.y)
        && (enemy->coord.y < (player->coord.y + 117))
        && (enemy->coord.x > player->coord.x - 100)
        && (enemy->coord.x < player->coord.x + 100))
            return 0;
    if (player->direction == UP)
        if ((enemy->coord.y < player->coord.y)
        && enemy->coord.y > (player->coord.y - 117)
        && (enemy->coord.x > player->coord.x - 100)
        && (enemy->coord.x < player->coord.x + 100))
            return 0;
    return 1;
}

int attack_range(enemy_t *enemy, player_t *player)
{
    if (horizontal_range(enemy, player) == 0)
        return 0;
    if (player->direction == LEFT)
        if ((enemy->coord.x < player->coord.x)
        && enemy->coord.x > (player->coord.x - 117)
        && (enemy->coord.y > player->coord.y - 100)
        && (enemy->coord.y < player->coord.y + 100))
            return 0;
    if (player->direction == RIGHT)
        if ((enemy->coord.x > player->coord.x)
        && enemy->coord.x < (player->coord.x + 117)
        && (enemy->coord.y > player->coord.y - 100)
        && (enemy->coord.y < player->coord.y + 100))
            return 0;
    return 1;
}

player_t *attack_player(player_t *player)
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

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** range_slinger
*/
#include "myrpg.h"

static int in_range_vertical(enemy_t *enemy, player_t *player)
{
    if (enemy->direction == LEFT)
        if ((player->coord.x < enemy->coord.x + 1000)
        && (player->coord.y > enemy->coord.y - 50
        && player->coord.y < enemy->coord.y + 50))
            return 0;
    if (enemy->direction == RIGHT)
        if ((player->coord.x > enemy->coord.x - 1000)
        && (player->coord.y > enemy->coord.y - 50
        && player->coord.y < enemy->coord.y + 50))
            return 0;
    return 1;
}

int in_range_for_slinger(enemy_t *enemy, player_t *player)
{
    if (enemy->direction == DOWN)
        if ((player->coord.y < enemy->coord.y + 1000)
        && (player->coord.x > enemy->coord.x - 50
        && player->coord.x < enemy->coord.x + 50))
            return 0;
    if (enemy->direction == UP)
        if ((player->coord.y > enemy->coord.y - 1000)
        && (player->coord.x > enemy->coord.x - 50
        && player->coord.x < enemy->coord.x + 50))
            return 0;
    if (in_range_vertical(enemy, player) == 0)
        return 0;
    return 1;
}

static int horizontal_range(player_t *player, enemy_t *enemy)
{
    if (enemy->direction == DOWN)
        if ((player->coord.y > enemy->coord.y)
        && (player->coord.y < (enemy->coord.y + 300))
        && (player->coord.x > enemy->coord.x - 300)
        && (player->coord.x < enemy->coord.x + 300))
            return 0;
    if (enemy->direction == UP)
        if ((player->coord.y < enemy->coord.y)
        && player->coord.y > (enemy->coord.y - 300)
        && (player->coord.x > enemy->coord.x - 300)
        && (player->coord.x < enemy->coord.x + 300))
            return 0;
    return 1;
}

int attack_range_slinger(player_t *player, enemy_t *enemy)
{
    if (horizontal_range(player, enemy) == 0)
        return 0;
    if (enemy->direction == LEFT)
        if ((player->coord.x < enemy->coord.x)
        && player->coord.x > (enemy->coord.x - 300)
        && (player->coord.y > enemy->coord.y - 300)
        && (player->coord.y < enemy->coord.y + 300))
            return 0;
    if (enemy->direction == RIGHT)
        if ((player->coord.x > enemy->coord.x)
        && player->coord.x < (enemy->coord.x + 300)
        && (player->coord.y > enemy->coord.y - 300)
        && (player->coord.y < enemy->coord.y + 300))
            return 0;
    return 1;
}

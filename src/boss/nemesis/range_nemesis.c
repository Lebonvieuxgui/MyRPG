/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** range_nemesis
*/
#include "myrpg.h"

static int in_range_vertical(boss_t *nemesis, player_t *player)
{
    if (nemesis->direction == LEFT)
        if ((player->coord.x < nemesis->coord.x)
        && player->coord.x > (nemesis->coord.x - 100)
        && (player->coord.y > nemesis->coord.y)
        && (player->coord.y < nemesis->coord.y + 200))
            return 0;
    if (nemesis->direction == RIGHT)
        if ((player->coord.x > nemesis->coord.x)
        && player->coord.x < (nemesis->coord.x + 200)
        && (player->coord.y > nemesis->coord.y - 30)
        && (player->coord.y < nemesis->coord.y + 110))
            return 0;
    return 1;
}

int in_range_nemesis(boss_t *nemesis, player_t *player)
{
    if (nemesis->direction == DOWN)
        if ((player->coord.y > nemesis->coord.y)
        && (player->coord.y < (nemesis->coord.y + 200))
        && (player->coord.x > nemesis->coord.x - 50)
        && (player->coord.x < nemesis->coord.x + 100))
            return 0;
    if (nemesis->direction == UP)
        if ((player->coord.y < nemesis->coord.y)
        && player->coord.y > (nemesis->coord.y - 100)
        && (player->coord.x > nemesis->coord.x - 100)
        && (player->coord.x < nemesis->coord.x + 100))
            return 0;
    if (in_range_vertical(nemesis, player) == 0)
        return 0;
    return 1;
}


static int horizontal_range(player_t *player, boss_t *nemesis)
{
    if (nemesis->direction == DOWN)
        if ((player->coord.y > nemesis->coord.y)
        && (player->coord.y < (nemesis->coord.y + 200))
        && (player->coord.x > nemesis->coord.x - 30)
        && (player->coord.x < nemesis->coord.x + 110))
            return 0;
    if (nemesis->direction == UP)
        if ((player->coord.y < nemesis->coord.y)
        && player->coord.y > (nemesis->coord.y - 100)
        && (player->coord.x > nemesis->coord.x - 20)
        && (player->coord.x < nemesis->coord.x + 120))
            return 0;
    return 1;
}

int attack_range_nemesis(player_t *player, boss_t *nemesis)
{
    if (horizontal_range(player, nemesis) == 0)
        return 0;
    if (nemesis->direction == LEFT)
        if ((player->coord.x < nemesis->coord.x)
        && player->coord.x > (nemesis->coord.x - 110)
        && (player->coord.y > nemesis->coord.y - 200)
        && (player->coord.y < nemesis->coord.y + 200))
            return 0;
    if (nemesis->direction == RIGHT)
        if ((player->coord.x > nemesis->coord.x)
        && player->coord.x < (nemesis->coord.x + 210)
        && (player->coord.y > nemesis->coord.y - 30)
        && (player->coord.y < nemesis->coord.y + 110))
            return 0;
    return 1;
}

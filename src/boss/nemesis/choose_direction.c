/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** choose_direction
*/
#include "myrpg.h"

boss_t *choose_direction_nemesis(boss_t *nemesis, player_t *player)
{
    if (nemesis->coord.x >= player->coord.x - 50
    && nemesis->coord.x <= player->coord.x + 20) {
        if (nemesis->coord.y < player->coord.y) {
            nemesis->direction = DOWN;
            nemesis->rect.top = 1152;
        } else {
            nemesis->direction = UP;
            nemesis->rect.top = 1440;
        }
    } else {
        if (nemesis->coord.x > player->coord.x) {
            nemesis->direction = LEFT;
            nemesis->rect.top = 1728;
        } else {
            nemesis->direction = RIGHT;
            nemesis->rect.top = 2016;
        }
    }
    return nemesis;
}

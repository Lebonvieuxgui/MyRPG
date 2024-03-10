/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** collision_nemesis
*/

#include "myrpg.h"

int collision_down_nemesis(game_object_t *game, boss_t *nemesis)
{
    if (check_black_or_white(game, nemesis->coord.x + 50,
    nemesis->coord.y - 30) == 0)
        return 0;
    return 1;
}

int collision_up_nemesis(game_object_t *game, boss_t *nemesis)
{
    if (check_black_or_white(game, nemesis->coord.x + 50,
    nemesis->coord.y - 180) == 0)
        return 0;
    return 1;
}

int collision_left_nemesis(game_object_t *game, boss_t *nemesis)
{
    if (check_black_or_white(game, nemesis->coord.x + 40,
    nemesis->coord.y - 43) == 0)
        return 0;
    return 1;
}

int collision_right_nemesis(game_object_t *game, boss_t *nemesis)
{
    if (check_black_or_white(game, nemesis->coord.x + 150,
    nemesis->coord.y - 43) == 0)
        return 0;
    return 1;
}
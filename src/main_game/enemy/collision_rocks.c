/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** collision_rocks
*/
#include "myrpg.h"

int collision_down_rock(game_object_t *game, projectile_t *rock)
{
    if (check_black_or_white(game, rock->coord.x,
    rock->coord.y - 170) == 0)
        return 0;
    else {
        rock->coord.x = -1000;
        rock->coord.y = -1000;
        rock->launched = sfFalse;
    }
    return 1;
}

int collision_up_rock(game_object_t *game, projectile_t *rock)
{
    if (check_black_or_white(game, rock->coord.x,
    rock->coord.y - 200) == 0)
        return 0;
    else {
        rock->coord.x = -1000;
        rock->coord.y = -1000;
        rock->launched = sfFalse;
    }
    return 1;
}

int collision_left_rock(game_object_t *game, projectile_t *rock)
{
    if (check_black_or_white(game, rock->coord.x,
    rock->coord.y - 190) == 0)
        return 0;
    else {
        rock->coord.x = -1000;
        rock->coord.y = -1000;
        rock->launched = sfFalse;
    }
    return 1;
}

int collision_right_rock(game_object_t *game, projectile_t *rock)
{
    if (check_black_or_white(game, rock->coord.x,
    rock->coord.y - 190) == 0)
        return 0;
    else {
        rock->coord.x = -1000;
        rock->coord.y = -1000;
        rock->launched = sfFalse;
    }
    return 1;
}

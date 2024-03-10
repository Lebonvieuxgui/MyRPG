/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** collision_projos_nemesis
*/
#include "myrpg.h"

int collision_down_projo(game_object_t *game, projectile_t *projo)
{
    if (check_black_or_white(game, projo->coord.x,
    projo->coord.y - 170) == 0)
        return 0;
    else {
        projo->coord.x = -1000;
        projo->coord.y = -1000;
        projo->launched = sfFalse;
    }
    return 1;
}

int collision_up_projo(game_object_t *game, projectile_t *projo)
{
    if (check_black_or_white(game, projo->coord.x,
    projo->coord.y - 200) == 0)
        return 0;
    else {
        projo->coord.x = -1000;
        projo->coord.y = -1000;
        projo->launched = sfFalse;
    }
    return 1;
}

int collision_left_projo(game_object_t *game, projectile_t *projo)
{
    if (check_black_or_white(game, projo->coord.x,
    projo->coord.y - 190) == 0)
        return 0;
    else {
        projo->coord.x = -1000;
        projo->coord.y = -1000;
        projo->launched = sfFalse;
    }
    return 1;
}

int collision_right_projo(game_object_t *game, projectile_t *projo)
{
    if (check_black_or_white(game, projo->coord.x,
    projo->coord.y - 190) == 0)
        return 0;
    else {
        projo->coord.x = -1000;
        projo->coord.y = -1000;
        projo->launched = sfFalse;
    }
    return 1;
}
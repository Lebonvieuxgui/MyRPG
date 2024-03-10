/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** collision_enemy
*/
#include "myrpg.h"

int collision_down_enemy(game_object_t *game, enemy_t *enemy)
{
    if (check_black_or_white(game, enemy->coord.x + 50,
    enemy->coord.y - 30) == 0)
        return 0;
    return 1;
}

int collision_up_enemy(game_object_t *game, enemy_t *enemy)
{
    if (check_black_or_white(game, enemy->coord.x + 50,
    enemy->coord.y - 180) == 0)
        return 0;
    return 1;
}

int collision_left_enemy(game_object_t *game, enemy_t *enemy)
{
    if (check_black_or_white(game, enemy->coord.x + 40,
    enemy->coord.y - 43) == 0)
        return 0;
    return 1;
}

int collision_right_enemy(game_object_t *game, enemy_t *enemy)
{
    if (check_black_or_white(game, enemy->coord.x + 150,
    enemy->coord.y - 43) == 0)
        return 0;
    return 1;
}

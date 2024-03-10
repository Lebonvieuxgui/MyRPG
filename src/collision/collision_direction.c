/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** collision_direction
*/

#include "myrpg.h"

int collision_down(game_object_t *game, int x, int y)
{
    if (game->player->coord.y < 4320) {
    if (check_black_or_white(game, game->player->coord.x + x,
    game->player->coord.y + y) == 0)
        return 0;
    }
    return 1;
}

int collision_up(game_object_t *game, int x, int y)
{
    if (game->player->coord.y > 0) {
    if (check_black_or_white(game, game->player->coord.x + x,
    game->player->coord.y + y) == 0)
        return 0;
    }
    return 1;
}

int collision_left(game_object_t *game, int x, int y)
{
    if (game->player->coord.x > 0) {
    if (check_black_or_white(game, game->player->coord.x + x,
    game->player->coord.y + y) == 0)
        return 0;
    }
    return 1;
}

int collision_right(game_object_t *game, int x, int y)
{
    if (game->player->coord.x < 7680) {
    if (check_black_or_white(game, game->player->coord.x + x,
    game->player->coord.y + y) == 0)
        return 0;
    }
    return 1;
}

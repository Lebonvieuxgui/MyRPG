/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** taked_keys
*/

#include "myrpg.h"

object_t **taked_keys(game_object_t *game)
{
    is_green_taked(game->objects, game->player);
    is_blue_taked(game->objects, game->player);
    is_yellow_taked(game->objects, game->player);
    is_red_taked(game->objects, game->player);
    return game->objects;
}

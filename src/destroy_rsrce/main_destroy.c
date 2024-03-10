/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** main_destroy
*/

#include "myrpg.h"

static void free_resource(game_object_t *game)
{
    free(game->HUD);
    free(game->heart);
    free(game->sign);
    free(game->doors);
    free(game->doorframes);
    free(game->objects);
    free(game->player);
    free(game->list_enemies);
    free(game->nemesis);
    free(game->menubutton);
    free(game->pausebutton);
    free(game->fire);
    free(game->window);
    free(game);
}

void main_destroy(game_object_t *game)
{
    if (!game)
        return;
    destroy_music(game, game->nemesis, game->player);
    destroy_sprite(game);
    destroy_texture(game);
    free_resource(game);
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** coord_view
*/

#include "myrpg.h"

static game_object_t *objects_taked(game_object_t *game)
{
    if (!game)
        return NULL;
    if (game->objects[0]->taked == sfFalse)
        sfRenderWindow_drawSprite(game->window->w,
        game->objects[0]->sprite, NULL);
    if (game->objects[1]->taked == sfFalse)
        sfRenderWindow_drawSprite(game->window->w, game->objects[1]->sprite,
        NULL);
    if (game->objects[2]->taked == sfFalse)
        sfRenderWindow_drawSprite(game->window->w, game->objects[2]->sprite,
        NULL);
    if (game->objects[3]->taked == sfFalse)
        sfRenderWindow_drawSprite(game->window->w, game->objects[3]->sprite,
        NULL);
    if (game->objects[4]->taked == sfFalse)
        sfRenderWindow_drawSprite(game->window->w, game->objects[4]->sprite,
        NULL);
    return game;
}

game_object_t *coord_view(game_object_t *game)
{
    if (!game)
        return NULL;
    if (game->GAMESTATE == GAME || game->GAMESTATE == INTRO) {
        game->coord_view.x = game->player->coord.x + 92;
        game->coord_view.y = game->player->coord.y + 92;
        sfView_setCenter(game->view, game->coord_view);
    } else
        move_camera(game);
    sfRenderWindow_setView(game->window->w, game->view);
    sfRenderWindow_drawSprite(game->window->w, game->map, NULL);
    print_HUD(game);
    objects_taked(game);
    if (game->objects[5]->taked == sfFalse)
        sfRenderWindow_drawSprite(game->window->w,
        game->objects[5]->sprite, NULL);
    return game;
}

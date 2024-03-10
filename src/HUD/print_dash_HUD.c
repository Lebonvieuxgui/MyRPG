/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** print_dash_HUD
*/

#include "myrpg.h"

void print_dash(game_object_t *game)
{
    game->HUD->dash->pos.x = game->coord_view.x - 465;
    game->HUD->dash->pos.y = game->coord_view.y + 430;
    sfSprite_setPosition(game->HUD->dash->sprite, game->HUD->dash->pos);
    if (game->objects[0]->taked == sfTrue)
        sfRenderWindow_drawSprite(game->window->w, game->HUD->dash->sprite,
        NULL);
}

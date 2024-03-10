/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** hover_game_over
*/

#include "myrpg.h"

static void hover_resume(game_object_t *game, button_t **gameover)
{
    sfVector2f size;
    sfVector2f pos;

    size.x = 1.1;
    size.y = 1.1;
    pos = game->gameover[1]->pos;
    sfSprite_setPosition(gameover[1]->sprite, (sfVector2f){pos.x - 20, pos.y});
    sfSprite_setScale(gameover[1]->sprite, size);
    sfRenderWindow_drawSprite(game->window->w, gameover[1]->sprite, NULL);
}

static void hover_quit(game_object_t *game, button_t **gameover)
{
    sfVector2f size;
    sfVector2f pos;

    size.x = 1.1;
    size.y = 1.1;
    pos = game->gameover[2]->pos;
    sfSprite_setPosition(gameover[2]->sprite, (sfVector2f){pos.x - 20, pos.y});
    sfSprite_setScale(gameover[2]->sprite, size);
    sfRenderWindow_drawSprite(game->window->w, gameover[2]->sprite, NULL);
}

void check_hover_go(game_object_t *game, button_t **gameover)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(game->window->w);

    if ((m.x >= 735 && m.x <= 1170) && (m.y >= 455 && m.y <= 560))
        hover_resume(game, gameover);
    if ((m.x >= 735 && m.x <= 1170) && (m.y >= 630 && m.y <= 735))
        hover_quit(game, gameover);
}
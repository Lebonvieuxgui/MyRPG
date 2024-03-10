/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** display_pause
*/

#include "myrpg.h"

static void display_buttons(game_object_t *game, sfVector2f position,
button_t **pause_buttons)
{
    sfVector2f size;

    size.x = 1;
    size.y = 1;
    sfSprite_setScale(pause_buttons[0]->sprite, size);
    sfSprite_setPosition(pause_buttons[0]->sprite, position);
    sfRenderWindow_drawSprite(game->window->w, pause_buttons[0]->sprite, NULL);
    position.y += 180;
    sfSprite_setPosition(pause_buttons[1]->sprite, position);
    sfSprite_setScale(pause_buttons[1]->sprite, size);
    sfRenderWindow_drawSprite(game->window->w, pause_buttons[1]->sprite, NULL);
    position.y += 182;
    sfSprite_setScale(pause_buttons[2]->sprite, size);
    sfSprite_setPosition(pause_buttons[2]->sprite, position);
    sfRenderWindow_drawSprite(game->window->w, pause_buttons[2]->sprite, NULL);
    position.y += 182;
    sfSprite_setScale(pause_buttons[3]->sprite, size);
    sfSprite_setPosition(pause_buttons[3]->sprite, position);
    sfRenderWindow_drawSprite(game->window->w, pause_buttons[3]->sprite, NULL);
}

void display_pause(game_object_t *game, button_t **pause_buttons)
{
    sfVector2f position;

    position.x = game->coord_view.x - 960;
    position.y = game->coord_view.y - 540;
    sfSprite_setPosition(game->pause, position);
    sfSprite_setPosition(game->darken, position);
    if (game->PAUSE == DO_NOT_EXIST) {
        sfRenderWindow_drawSprite(game->window->w, game->darken, NULL);
        game->PAUSE = EXIST;
    }
    sfRenderWindow_drawSprite(game->window->w, game->pause, NULL);
    position.x += 750;
    position.y += 215;
    display_buttons(game, position, pause_buttons);
    check_pause_buttons(game, pause_buttons);
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** hover_pause
*/

#include "myrpg.h"

static void hover_resume(game_object_t *game, button_t **pause_buttons)
{
    sfVector2f size;
    sfVector2f pos;

    size.x = 1.2;
    size.y = 1.2;
    pos.x = game->coord_view.x - 250;
    pos.y = game->coord_view.y - 340;
    sfSprite_setPosition(pause_buttons[0]->sprite, pos);
    sfSprite_setScale(pause_buttons[0]->sprite, size);
    sfRenderWindow_drawSprite(game->window->w, pause_buttons[0]->sprite, NULL);
}

static void hover_settings(game_object_t *game, button_t **pause_buttons)
{
    sfVector2f size;
    sfVector2f pos;

    size.x = 1.2;
    size.y = 1.2;
    pos.x = game->coord_view.x - 250;
    pos.y = game->coord_view.y - 155;
    sfSprite_setPosition(pause_buttons[1]->sprite, pos);
    sfSprite_setScale(pause_buttons[1]->sprite, size);
    sfRenderWindow_drawSprite(game->window->w, pause_buttons[1]->sprite, NULL);
}

static void hover_home(game_object_t *game, button_t **pause_buttons)
{
    sfVector2f size;
    sfVector2f pos;

    size.x = 1.2;
    size.y = 1.2;
    pos.x = game->coord_view.x - 250;
    pos.y = game->coord_view.y + 30;
    sfSprite_setPosition(pause_buttons[2]->sprite, pos);
    sfSprite_setScale(pause_buttons[2]->sprite, size);
    sfRenderWindow_drawSprite(game->window->w, pause_buttons[2]->sprite, NULL);
}

static void hover_quit(game_object_t *game, button_t **pause_buttons)
{
    sfVector2f size;
    sfVector2f pos;

    size.x = 1.2;
    size.y = 1.2;
    pos.x = game->coord_view.x - 250;
    pos.y = game->coord_view.y + 210;
    sfSprite_setPosition(pause_buttons[3]->sprite, pos);
    sfSprite_setScale(pause_buttons[3]->sprite, size);
    sfRenderWindow_drawSprite(game->window->w, pause_buttons[3]->sprite, NULL);
}

void check_hover_pause(game_object_t *game, button_t **pause_buttons)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(game->window->w);

    if ((m.x >= 735 && m.x <= 1170) && (m.y >= 200 && m.y <= 300))
        hover_resume(game, pause_buttons);
    if ((m.x >= 735 && m.x <= 1170) && (m.y >= 350 && m.y <= 450))
        hover_settings(game, pause_buttons);
    if ((m.x >= 735 && m.x <= 1170) && (m.y >= 525 && m.y <= 640))
        hover_home(game, pause_buttons);
    if ((m.x >= 735 && m.x <= 1170) && (m.y >= 690 && m.y <= 820))
        hover_quit(game, pause_buttons);
}

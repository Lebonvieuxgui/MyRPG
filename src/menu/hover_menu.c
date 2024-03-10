/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** hover_menu
*/
#include "myrpg.h"

static void hover_one(game_object_t *game, button_t **menu_buttons)
{
    sfRenderWindow_drawSprite(game->window->w, menu_buttons[2]->sprite, NULL);
}

static void hover_two(game_object_t *game, button_t **menu_buttons)
{
    sfRenderWindow_drawSprite(game->window->w, menu_buttons[4]->sprite, NULL);
}

static void hover_three(game_object_t *game, button_t **menu_buttons)
{
    sfRenderWindow_drawSprite(game->window->w, menu_buttons[6]->sprite, NULL);
}

void hover_menu(game_object_t *game, button_t **menu_buttons)
{
    if (menu_buttons[5]->state != IS_CLICKED) {
        sfVector2i m = sfMouse_getPositionRenderWindow(game->window->w);
        if ((m.x >= 750 && m.x <= 1110) && (m.y >= 360 && m.y <= 490))
            hover_one(game, menu_buttons);
        if ((m.x >= 750 && m.x <= 1100) && (m.y >= 500 && m.y <= 630))
            hover_two(game, menu_buttons);
        if ((m.x >= 1350 && m.x <= 1700) && (m.y >= 440 && m.y <= 560))
            hover_three(game, menu_buttons);
        if ((m.x >= 150 && m.x <= 510) && (m.y >= 440 && m.y <= 560))
            sfRenderWindow_drawSprite(game->window->w,
            menu_buttons[9]->sprite, NULL);
    }
}

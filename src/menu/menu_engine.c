/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** menu_engine
*/

#include "myrpg.h"

void draw_menu(game_object_t *game, button_t **menu_buttons)
{
    sfRenderWindow_clear(game->window->w, sfBlack);
    sfRenderWindow_drawSprite(game->window->w, menu_buttons[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->w, menu_buttons[1]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->w, menu_buttons[3]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->w, menu_buttons[5]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->w, game->fire->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->w, menu_buttons[8]->sprite, NULL);
    if (menu_buttons[5]->state == IS_CLICKED)
        sfRenderWindow_drawSprite(game->window->w, menu_buttons[7]->sprite,
        NULL);
}

game_object_t *menu_engine(game_object_t *game)
{
    if (!game)
        return NULL;
    gest_chrono_fire(game->fire);
    sfSprite_setTextureRect(game->fire->sprite, game->fire->rect);
    draw_menu(game, game->menubutton);
    sfRenderWindow_setMouseCursorVisible(game->window->w, sfTrue);
    events_menu(game, game->menubutton);
    check_menu_buttons(game, game->menubutton);
    hover_menu(game, game->menubutton);
    sfRenderWindow_display(game->window->w);
    return game;
}

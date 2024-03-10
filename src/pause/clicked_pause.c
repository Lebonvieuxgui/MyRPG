/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** clicked_pause
*/
#include "myrpg.h"

void clicked_resume(game_object_t *game, button_t **pause_buttons)
{
    sfVector2f size;
    sfVector2f pos;

    size.x = 1.2;
    size.y = 1.2;
    pos.x = game->coord_view.x - 250;
    pos.y = game->coord_view.y - 340;
    pause_buttons[0]->rect.left = 200;
    sfSprite_setPosition(pause_buttons[0]->sprite, pos);
    sfSprite_setScale(pause_buttons[0]->sprite, size);
    sfRenderWindow_drawSprite(game->window->w, pause_buttons[0]->sprite, NULL);
}

void clicked_settings(game_object_t *game, button_t **pause_buttons)
{
    sfVector2f size;
    sfVector2f pos;

    size.x = 1.2;
    size.y = 1.2;
    pos.x = game->coord_view.x - 250;
    pos.y = game->coord_view.y - 155;
    pause_buttons[1]->rect.left = 200;
    sfSprite_setPosition(pause_buttons[1]->sprite, pos);
    sfSprite_setScale(pause_buttons[1]->sprite, size);
    sfRenderWindow_drawSprite(game->window->w, pause_buttons[1]->sprite, NULL);
}

void clicked_home(game_object_t *game, button_t **pause_buttons)
{
    sfVector2f size;
    sfVector2f pos;

    size.x = 1.2;
    size.y = 1.2;
    pos.x = game->coord_view.x - 250;
    pos.y = game->coord_view.y + 30;
    pause_buttons[2]->rect.left = 200;
    sfSprite_setPosition(pause_buttons[2]->sprite, pos);
    sfSprite_setScale(pause_buttons[2]->sprite, size);
    sfRenderWindow_drawSprite(game->window->w, pause_buttons[2]->sprite, NULL);

}

void clicked_quit(game_object_t *game, button_t **pause_buttons)
{
    sfVector2f size;
    sfVector2f pos;

    size.x = 1.2;
    size.y = 1.2;
    pos.x = game->coord_view.x - 250;
    pos.y = game->coord_view.y + 210;
    pause_buttons[3]->rect.left = 200;
    sfSprite_setPosition(pause_buttons[3]->sprite, pos);
    sfSprite_setScale(pause_buttons[3]->sprite, size);
    sfRenderWindow_drawSprite(game->window->w, pause_buttons[3]->sprite, NULL);
}

/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** manage event
*/
#include "myrpg.h"

void manage_event(game_object_t *game)
{
    sfEvent event;

    if (!game)
        return;
    while (sfRenderWindow_pollEvent(game->window->w, &event)) {
        keyboard_input_event(game, event);
    }
}

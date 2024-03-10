/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** window
*/
#include "myrpg.h"

void close_window_event(game_object_t *game, sfEvent *event)
{
    if (!game)
        return;
    if (event->type == sfEvtClosed || event->key.code == sfKeyQ)
        sfRenderWindow_close(game->window->w);
}

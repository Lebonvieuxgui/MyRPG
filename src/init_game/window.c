/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create window
*/
#include "myrpg.h"

my_window_t *create_window(void)
{
    my_window_t *window = malloc(sizeof(my_window_t));

    if (!window)
        return NULL;
    window->height = 1080;
    window->width = 1920;
    window->framelimit = 32;
    window->mode = (sfVideoMode){window->width, window->height,
    window->framelimit};
    window->w = sfRenderWindow_create(window->mode, "my_rpg", sfResize
    | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->w, 60);
    return window;
}

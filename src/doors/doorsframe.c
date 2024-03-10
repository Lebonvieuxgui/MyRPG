/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** init_doorsframe
*/

#include "myrpg.h"

static button_t *init_door(game_object_t *game, int i)
{
    game->doorframes[i] = malloc(sizeof(button_t));
    game->doorframes[i]->sprite = create_sprite("Rsrce/porte.png");
    return game->doorframes[i];
}

button_t **init_doorframes(game_object_t *game)
{
    int i = 0;

    game->doorframes = malloc(sizeof(button_t)* 5);
    while (i < 4) {
        init_door(game, i);
        i += 1;
    }
    game->heart[i] = NULL;
    return game->doorframes;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** init_hud_lives
*/

#include "myrpg.h"

button_t **create_hud_heart(void)
{
    button_t **live = malloc(sizeof(button_t)* 7);

    live[0] = malloc(sizeof(button_t));
    live[0]->sprite = create_sprite("Rsrce/heart.png");
    live[1] = malloc(sizeof(button_t));
    live[1]->sprite = create_sprite("Rsrce/heart.png");
    live[2] = malloc(sizeof(button_t));
    live[2]->sprite = create_sprite("Rsrce/heart.png");
    live[3] = malloc(sizeof(button_t));
    live[3]->sprite = create_sprite("Rsrce/heart.png");
    live[4] = malloc(sizeof(button_t));
    live[4]->sprite = create_sprite("Rsrce/heart.png");
    live[5] = malloc(sizeof(button_t));
    live[5]->sprite = create_sprite("Rsrce/heart.png");
    live[6] = malloc(sizeof(button_t));
    live[6]->sprite = create_sprite("Rsrce/heart.png");
    live[7] = NULL;
    return live;
}

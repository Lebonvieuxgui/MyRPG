/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** game_over
*/

#include "myrpg.h"

button_t **init_game_over(void)
{
    button_t **gameover = malloc(sizeof(button_t) * 4);

    if (!gameover)
        return NULL;
    gameover[0] = malloc(sizeof(button_t));
    gameover[0]->sprite = create_sprite("Rsrce/gameover.png");
    gameover[1] = malloc(sizeof(button_t));
    gameover[1]->sprite = create_sprite("Rsrce/Resume.png");
    gameover[2] = malloc(sizeof(button_t));
    gameover[2]->state = ISNT_CLICKED;
    gameover[2]->sprite = create_sprite("Rsrce/Quit.png");
    gameover[3] = malloc(sizeof(button_t));
    gameover[3]->state = ISNT_CLICKED;
    gameover[3]->sprite = create_sprite("Rsrce/Hudboard.png");
    return gameover;
}

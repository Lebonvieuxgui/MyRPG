/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** init_pause
*/
#include "myrpg.h"

static button_t **end_creating_pause_buttons(button_t **pause_buttons)
{
    pause_buttons[2]->rect.height = 110;
    pause_buttons[2]->rect.width = 426;
    pause_buttons[2]->rect.left = 0;
    pause_buttons[2]->rect.top = 0;
    sfSprite_setTextureRect(pause_buttons[2]->sprite, pause_buttons[2]->rect);
    pause_buttons[3] = malloc(sizeof(button_t));
    pause_buttons[3]->state = ISNT_CLICKED;
    pause_buttons[3]->sprite = create_sprite("Rsrce/quitsprite.png");
    pause_buttons[3]->chrono = create_chrono();
    pause_buttons[3]->rect.height = 110;
    pause_buttons[3]->rect.width = 426;
    pause_buttons[3]->rect.left = 0;
    pause_buttons[3]->rect.top = 0;
    sfSprite_setTextureRect(pause_buttons[3]->sprite, pause_buttons[3]->rect);
    pause_buttons[4] = NULL;
    return pause_buttons;
}
static button_t **keep_creating_pause_buttons(button_t **pause_buttons)
{
    pause_buttons[1]->rect.height = 110;
    pause_buttons[1]->rect.width = 426;
    pause_buttons[1]->rect.left = 0;
    pause_buttons[1]->rect.top = 0;
    sfSprite_setTextureRect(pause_buttons[1]->sprite, pause_buttons[1]->rect);
    pause_buttons[2] = malloc(sizeof(button_t));
    pause_buttons[2]->state = ISNT_CLICKED;
    pause_buttons[2]->sprite = create_sprite("Rsrce/homesprite.png");
    pause_buttons[2]->chrono = create_chrono();
    end_creating_pause_buttons(pause_buttons);
    return pause_buttons;
}

button_t **create_pause_buttons()
{
    button_t **pause_buttons = malloc(sizeof(button_t)* 5);

    pause_buttons[0] = malloc(sizeof(button_t));
    pause_buttons[0]->state = ISNT_CLICKED;
    pause_buttons[0]->sprite = create_sprite("Rsrce/resumesprite.png");
    pause_buttons[0]->chrono = create_chrono();
    pause_buttons[0]->rect.height = 110;
    pause_buttons[0]->rect.width = 426;
    pause_buttons[0]->rect.left = 0;
    pause_buttons[0]->rect.top = 0;
    sfSprite_setTextureRect(pause_buttons[0]->sprite, pause_buttons[0]->rect);
    pause_buttons[1] = malloc(sizeof(button_t));
    pause_buttons[1]->state = ISNT_CLICKED;
    pause_buttons[1]->sprite = create_sprite("Rsrce/settingssprite.png");
    pause_buttons[1]->chrono = create_chrono();
    keep_creating_pause_buttons(pause_buttons);
    return pause_buttons;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** init_settings
*/

#include "myrpg.h"

button_t **create_settings_buttons(void)
{
    button_t **settings = malloc(sizeof(button_t) * 9);

    if (!settings)
        return NULL;
    settings[0] = malloc(sizeof(button_t));
    settings[0]->sprite = create_sprite("Rsrce/Quit.png");
    sfSprite_setScale(settings[0]->sprite, (sfVector2f) {1, 1});
    settings[1] = malloc(sizeof(button_t));
    settings[1]->sprite = create_sprite("Rsrce/Quit.png");
    sfSprite_setScale(settings[1]->sprite, (sfVector2f) {1.1, 1.1});
    settings[1]->state = ISNT_CLICKED;
    settings[2] = malloc(sizeof(button_t));
    settings[2]->sprite = create_sprite("Rsrce/button_next.png");
    settings[3] = malloc(sizeof(button_t));
    settings[3]->sprite = create_sprite("Rsrce/button_prev.png");
    settings[4] = malloc(sizeof(button_t));
    settings[4]->sprite = create_sprite("Rsrce/button_prev.png");
    settings[5] = malloc(sizeof(button_t));
    settings[5]->sprite = create_sprite("Rsrce/button_next.png");
    settings[6] = malloc(sizeof(button_t));
    settings[6]->sprite = create_sprite("Rsrce/button_next.png");
    settings[7] = malloc(sizeof(button_t));
    settings[7]->sprite = create_sprite("Rsrce/button_prev.png");
    settings[8] = NULL;
    return settings;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** init_menu
*/

#include "myrpg.h"

sfSprite *create_sprite(char *texture)
{
    sfSprite *s;
    sfTexture *t = sfTexture_createFromFile(texture, NULL);

    s = sfSprite_create();
    sfSprite_setTexture(s, t, sfTrue);
    return (s);
}

static button_t **continue_to_create_button(button_t **menu_buttons)
{
    if (!menu_buttons)
        return NULL;
    menu_buttons[4] = malloc(sizeof(button_t));
    menu_buttons[4]->sprite = create_sprite("Rsrce/Exit.png");
    sfSprite_scale(menu_buttons[4]->sprite, (sfVector2f) {1.1, 1.1});
    sfSprite_setPosition(menu_buttons[4]->sprite, (sfVector2f) {730, 540});
    menu_buttons[5] = malloc(sizeof(button_t));
    menu_buttons[5]->state = ISNT_CLICKED;
    menu_buttons[5]->sprite = create_sprite("Rsrce/Howtoplay.png");
    sfSprite_setPosition(menu_buttons[5]->sprite, (sfVector2f) {1350, 475});
    menu_buttons[6] = malloc(sizeof(button_t));
    menu_buttons[6]->sprite = create_sprite("Rsrce/Howtoplay.png");
    sfSprite_scale(menu_buttons[6]->sprite, (sfVector2f) {1.1, 1.1});
    sfSprite_setPosition(menu_buttons[6]->sprite, (sfVector2f) {1338, 463});
    menu_buttons[7] = malloc(sizeof(button_t));
    menu_buttons[7]->sprite = create_sprite("Rsrce/Htp.png");
    menu_buttons[8] = malloc(sizeof(button_t));
    menu_buttons[8]->state = ISNT_CLICKED;
    menu_buttons[8]->sprite = create_sprite("Rsrce/button_settings.png");
    sfSprite_setPosition(menu_buttons[8]->sprite, (sfVector2f) {150, 475});
    menu_buttons[9] = malloc(sizeof(button_t));
    menu_buttons[9]->sprite = create_sprite("Rsrce/button_settings.png");
    sfSprite_scale(menu_buttons[9]->sprite, (sfVector2f) {1.1, 1.1});
    sfSprite_setPosition(menu_buttons[9]->sprite, (sfVector2f) {138, 463});
    return menu_buttons;
}

button_t **create_menu_buttons(void)
{
    button_t **menu_buttons = malloc(sizeof(button_t)* 10);

    if (!menu_buttons)
        return NULL;
    menu_buttons[0] = malloc(sizeof(button_t));
    menu_buttons[0]->sprite = create_sprite("Rsrce/Menu.png");
    menu_buttons[1] = malloc(sizeof(button_t));
    menu_buttons[1]->state = ISNT_CLICKED;
    menu_buttons[1]->sprite = create_sprite("Rsrce/start.png");
    sfSprite_setPosition(menu_buttons[1]->sprite, (sfVector2f) {750, 400});
    menu_buttons[2] = malloc(sizeof(button_t));
    menu_buttons[2]->sprite = create_sprite("Rsrce/start.png");
    sfSprite_scale(menu_buttons[2]->sprite, (sfVector2f) {1.1, 1.1});
    sfSprite_setPosition(menu_buttons[2]->sprite, (sfVector2f) {730, 390});
    menu_buttons[3] = malloc(sizeof(button_t));
    menu_buttons[3]->state = ISNT_CLICKED;
    menu_buttons[3]->sprite = create_sprite("Rsrce/Exit.png");
    sfSprite_setPosition(menu_buttons[3]->sprite, (sfVector2f) {750, 550});
    menu_buttons = continue_to_create_button(menu_buttons);
    return menu_buttons;
}

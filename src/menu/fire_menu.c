/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** fire_menu
*/

#include "myrpg.h"

int move_rect_enemy(sfIntRect rect, int value, int offset, int max_value)
{
    if (rect.left > max_value) {
        rect.left = offset;
        return (rect.left);
    } else {
        rect.left = rect.left + value;
        return (rect.left);
    }
    return (FAILURE);
}

void start_chrono(game_clock_t *chrono)
{
    chrono->time = sfClock_getElapsedTime(chrono->clock);
    chrono->seconds = chrono->time.microseconds / 1200000.0;
}

button_t *gest_chrono_fire(button_t *fire)
{
    if (!fire)
        return NULL;
    start_chrono(fire->chrono);
    if (fire->chrono->seconds > 0.1) {
        fire->rect.left = move_rect_enemy(fire->rect, 240, 0, 2500);
        sfClock_restart(fire->chrono->clock);
    }
    return fire;
}

button_t *create_fire(void)
{
    button_t *fire = malloc(sizeof(button_t));

    if (!fire)
        return NULL;
    fire->texture = sfTexture_createFromFile("Rsrce/menusprite.png", NULL);
    fire->sprite = sfSprite_create();
    fire->rect.height = 164;
    fire->rect.width = 240;
    fire->rect.top = 0;
    fire->rect.left = 0;
    fire->pos.y = 669;
    fire->pos.x = 450;
    fire->chrono = create_chrono();
    fire->scale.x = 2.5;
    fire->scale.y = 2.5;
    sfSprite_setScale(fire->sprite, fire->scale);
    sfSprite_setPosition(fire->sprite, fire->pos);
    sfSprite_setTexture(fire->sprite, fire->texture, sfFalse);
    sfSprite_setTextureRect(fire->sprite, fire->rect);
    return (fire);
}

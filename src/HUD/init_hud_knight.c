/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** init_hud_knight
*/

#include "myrpg.h"

button_t *gest_chrono_hud_knight(button_t *HUD)
{
    start_chrono(HUD->chrono);
    if (HUD->chrono->seconds > 0.15) {
        HUD->rect.left = move_rect_enemy(HUD->rect, 200, 0, 1700);
        sfClock_restart(HUD->chrono->clock);
        sfSprite_setTextureRect(HUD->sprite, HUD->rect);
    }
    return HUD;
}

button_t *create_hud_knight()
{
    button_t *HUD = malloc(sizeof(button_t));
    sfVector2f size;

    HUD->texture = sfTexture_createFromFile("Rsrce/Hudknight.png", NULL);
    HUD->sprite = sfSprite_create();
    HUD->rect.height = 200;
    HUD->rect.width = 200;
    HUD->rect.top = 0;
    HUD->rect.left = 0;
    HUD->chrono = create_chrono();
    size.x = 0.94;
    size.y = 0.94;
    sfSprite_setScale(HUD->sprite, size);
    sfSprite_setPosition(HUD->sprite, HUD->pos);
    sfSprite_setTexture(HUD->sprite, HUD->texture, sfFalse);
    sfSprite_setTextureRect(HUD->sprite, HUD->rect);
    return HUD;
}

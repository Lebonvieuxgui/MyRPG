/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** block_medal
*/
#include "myrpg.h"

object_t *create_block_medal(void)
{
    object_t *medal = malloc(sizeof(object_t));

    medal->text = sfTexture_createFromFile("Rsrce/block_medal.png", NULL);
    medal->sprite = sfSprite_create();
    medal->chrono_anim.clock = sfClock_create();
    medal->rect.height = 100;
    medal->rect.width = 64;
    medal->coord.y = 670;
    medal->coord.x = 4270;
    medal->rect.left = 0;
    medal->rect.top = 0;
    medal->taked = sfFalse;
    sfSprite_setPosition(medal->sprite, medal->coord);
    sfSprite_setTextureRect(medal->sprite, medal->rect);
    sfSprite_setTexture(medal->sprite, medal->text, sfFalse);
    return medal;
}

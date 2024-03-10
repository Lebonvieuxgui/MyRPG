/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** objects
*/
#include "myrpg.h"

object_t **taked_objects(object_t **objects, player_t *player)
{
    if (player->coord.x > objects[0]->coord.x - 120
    && player->coord.x < objects[0]->coord.x + 120
    && player->coord.y > objects[0]->coord.y - 120
    && player->coord.y < objects[0]->coord.y + 120) {
        objects[0]->taked = sfTrue;
        player->dash = sfTrue;
    }
    if (player->coord.x > objects[5]->coord.x - 120
    && player->coord.x < objects[5]->coord.x + 120
    && player->coord.y > objects[5]->coord.y - 120
    && player->coord.y < objects[5]->coord.y + 120) {
        objects[5]->taked = sfTrue;
        player->block = sfTrue;
    }
    return objects;
}

object_t *medal_animation(object_t *medal)
{
    medal->chrono_anim = get_chrono(medal->chrono_anim);
    if (medal->chrono_anim.seconds > 0.2 && medal->taked == sfFalse) {
        medal->rect.left = medal->rect.left + 64;
        if (medal->rect.left > 570)
            medal->rect.left = 0;
        sfSprite_setTextureRect(medal->sprite, medal->rect);
        sfClock_restart(medal->chrono_anim.clock);
    }
    return medal;
}

object_t **create_objects(void)
{
    object_t **objects = malloc(sizeof(object_t *) * 7);
    objects[0] = create_dash_medal();
    objects[1] = init_green_key();
    objects[2] = init_blue_key();
    objects[3] = init_yellow_key();
    objects[4] = init_red_key();
    objects[5] = create_block_medal();
    objects[6] = NULL;
    return objects;
}

object_t *create_dash_medal(void)
{
    object_t *medal = malloc(sizeof(object_t));

    medal->text = sfTexture_createFromFile("Rsrce/dash_medal.png", NULL);
    medal->sprite = sfSprite_create();
    medal->chrono_anim.clock = sfClock_create();
    medal->rect.height = 100;
    medal->rect.width = 64;
    medal->coord.y = 3490;
    medal->coord.x = 4390;
    medal->rect.left = 0;
    medal->rect.top = 0;
    medal->taked = sfFalse;
    sfSprite_setPosition(medal->sprite, medal->coord);
    sfSprite_setTextureRect(medal->sprite, medal->rect);
    sfSprite_setTexture(medal->sprite, medal->text, sfFalse);
    return medal;
}

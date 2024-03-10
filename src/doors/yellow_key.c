/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** init_keys
*/

#include "myrpg.h"

static sfSound *create_sound(void)
{
    sfSound *sounds = malloc(sizeof(sfSound *) * 1);

    sounds = sfSound_create();
    sfSound_setBuffer(sounds, \
    sfSoundBuffer_createFromFile("Rsrce/Door_open.ogg"));
    sfSound_setVolume(sounds, 100);
    return sounds;
}

object_t **is_yellow_taked(object_t **objects, player_t *player)
{
    static int i = 0;

    if (player->coord.x > objects[3]->coord.x - 120
    && player->coord.x < objects[3]->coord.x + 120
    && player->coord.y > objects[3]->coord.y - 120
    && player->coord.y < objects[3]->coord.y + 120
    && i == 0) {
        sfSound_play(objects[3]->sound);
        objects[3]->taked = sfTrue;
        i = 1;
    }
    return objects;
}

object_t *key_yellow_animation(object_t *yellowkey)
{
    yellowkey->chrono_anim = get_chrono(yellowkey->chrono_anim);
    if (yellowkey->chrono_anim.seconds > 0.1 && yellowkey->taked == sfFalse) {
        yellowkey->rect.left = yellowkey->rect.left + 45;
        if (yellowkey->rect.left > 300)
            yellowkey->rect.left = 0;
        sfSprite_setTextureRect(yellowkey->sprite, yellowkey->rect);
        sfClock_restart(yellowkey->chrono_anim.clock);
    }
    return yellowkey;
}

object_t *init_yellow_key(void)
{
    object_t *yellowkey = malloc(sizeof(object_t));

    yellowkey->text = sfTexture_createFromFile("Rsrce/yellowkey.png", NULL);
    yellowkey->sprite = sfSprite_create();
    yellowkey->chrono_anim.clock = sfClock_create();
    yellowkey->rect.height = 160;
    yellowkey->rect.width = 45;
    yellowkey->coord.x = 5500;
    yellowkey->coord.y = 500;
    yellowkey->rect.left = 0;
    yellowkey->rect.top = 0;
    yellowkey->scale.x = 0.6;
    yellowkey->sound = create_sound();
    yellowkey->scale.y = 0.6;
    yellowkey->taked = sfFalse;
    sfSprite_setPosition(yellowkey->sprite, yellowkey->coord);
    sfSprite_setTextureRect(yellowkey->sprite, yellowkey->rect);
    sfSprite_setTexture(yellowkey->sprite, yellowkey->text, sfFalse);
    sfSprite_setScale(yellowkey->sprite, yellowkey->scale);
    return yellowkey;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** red_key
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

object_t **is_red_taked(object_t **objects, player_t *player)
{
    static int i = 0;

    if (player->coord.x > objects[4]->coord.x - 120
    && player->coord.x < objects[4]->coord.x + 120
    && player->coord.y > objects[4]->coord.y - 120
    && player->coord.y < objects[4]->coord.y + 120
    && i == 0) {
        sfSound_play(objects[4]->sound);
        objects[4]->taked = sfTrue;
        i = 1;
    }
    return objects;
}

object_t *key_red_animation(object_t *redkey)
{
    redkey->chrono_anim = get_chrono(redkey->chrono_anim);
    if (redkey->chrono_anim.seconds > 0.1 && redkey->taked == sfFalse) {
        redkey->rect.left = redkey->rect.left + 45;
        if (redkey->rect.left > 300)
            redkey->rect.left = 0;
        sfSprite_setTextureRect(redkey->sprite, redkey->rect);
        sfClock_restart(redkey->chrono_anim.clock);
    }
    return redkey;
}

object_t *init_red_key(void)
{
    object_t *redkey = malloc(sizeof(object_t));

    redkey->text = sfTexture_createFromFile("Rsrce/redkey.png", NULL);
    redkey->sprite = sfSprite_create();
    redkey->chrono_anim.clock = sfClock_create();
    redkey->rect.height = 160;
    redkey->rect.width = 45;
    redkey->coord.x = 6800;
    redkey->coord.y = 4200;
    redkey->rect.left = 0;
    redkey->rect.top = 0;
    redkey->scale.x = 0.6;
    redkey->scale.y = 0.6;
    redkey->sound = create_sound();
    redkey->taked = sfFalse;
    sfSprite_setPosition(redkey->sprite, redkey->coord);
    sfSprite_setTextureRect(redkey->sprite, redkey->rect);
    sfSprite_setTexture(redkey->sprite, redkey->text, sfFalse);
    sfSprite_setScale(redkey->sprite, redkey->scale);
    return redkey;
}

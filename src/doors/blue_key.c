/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** blue_key
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

object_t **is_blue_taked(object_t **objects, player_t *player)
{
    static int i = 0;

    if (player->coord.x > objects[2]->coord.x - 120
    && player->coord.x < objects[2]->coord.x + 120
    && player->coord.y > objects[2]->coord.y - 120
    && player->coord.y < objects[2]->coord.y + 120
    && i == 0) {
        sfSound_play(objects[2]->sound);
        objects[2]->taked = sfTrue;
        i = 1;
    }
    return objects;
}

object_t *key_blue_animation(object_t *bluekey)
{
    bluekey->chrono_anim = get_chrono(bluekey->chrono_anim);
    if (bluekey->chrono_anim.seconds > 0.1 && bluekey->taked == sfFalse) {
        bluekey->rect.left = bluekey->rect.left + 45;
        if (bluekey->rect.left > 300)
            bluekey->rect.left = 0;
        sfSprite_setTextureRect(bluekey->sprite, bluekey->rect);
        sfClock_restart(bluekey->chrono_anim.clock);
    }
    return bluekey;
}

object_t *init_blue_key(void)
{
    object_t *bluekey = malloc(sizeof(object_t));

    bluekey->text = sfTexture_createFromFile("Rsrce/bluekey.png", NULL);
    bluekey->sprite = sfSprite_create();
    bluekey->chrono_anim.clock = sfClock_create();
    bluekey->rect.height = 160;
    bluekey->rect.width = 45;
    bluekey->coord.x = 6150;
    bluekey->coord.y = 1250;
    bluekey->rect.left = 0;
    bluekey->rect.top = 0;
    bluekey->scale.x = 0.6;
    bluekey->sound = create_sound();
    bluekey->scale.y = 0.6;
    bluekey->taked = sfFalse;
    sfSprite_setPosition(bluekey->sprite, bluekey->coord);
    sfSprite_setTextureRect(bluekey->sprite, bluekey->rect);
    sfSprite_setTexture(bluekey->sprite, bluekey->text, sfFalse);
    sfSprite_setScale(bluekey->sprite, bluekey->scale);
    return bluekey;
}

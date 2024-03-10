/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** green_key
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

object_t **is_green_taked(object_t **objects, player_t *player)
{
    static int i = 0;

    if (player->coord.x > objects[1]->coord.x - 120
    && player->coord.x < objects[1]->coord.x + 120
    && player->coord.y > objects[1]->coord.y - 120
    && player->coord.y < objects[1]->coord.y + 120
    && i == 0) {
        sfSound_play(objects[1]->sound);
        objects[1]->taked = sfTrue;
        i = 1;
    }
    return objects;
}

object_t *key_green_animation(object_t *greenkey)
{
    greenkey->chrono_anim = get_chrono(greenkey->chrono_anim);
    if (greenkey->chrono_anim.seconds > 0.1 && greenkey->taked == sfFalse) {
        greenkey->rect.left = greenkey->rect.left + 45;
        if (greenkey->rect.left > 300)
            greenkey->rect.left = 0;
        sfSprite_setTextureRect(greenkey->sprite, greenkey->rect);
        sfClock_restart(greenkey->chrono_anim.clock);
    }
    return greenkey;
}

object_t *init_green_key(void)
{
    object_t *greenkey = malloc(sizeof(object_t));

    greenkey->text = sfTexture_createFromFile("Rsrce/greenkey.png", NULL);
    greenkey->sprite = sfSprite_create();
    greenkey->chrono_anim.clock = sfClock_create();
    greenkey->rect.height = 160;
    greenkey->rect.width = 45;
    greenkey->coord.x = 300;
    greenkey->coord.y = 850;
    greenkey->rect.left = 0;
    greenkey->rect.top = 0;
    greenkey->scale.x = 0.6;
    greenkey->sound = create_sound();
    greenkey->scale.y = 0.6;
    greenkey->taked = sfFalse;
    sfSprite_setPosition(greenkey->sprite, greenkey->coord);
    sfSprite_setTextureRect(greenkey->sprite, greenkey->rect);
    sfSprite_setTexture(greenkey->sprite, greenkey->text, sfFalse);
    sfSprite_setScale(greenkey->sprite, greenkey->scale);
    return greenkey;
}

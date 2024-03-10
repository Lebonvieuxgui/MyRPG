/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** create_nemesis
*/
#include "myrpg.h"

static sfSound **create_sounds(void)
{
    sfSound **sounds = malloc(sizeof(sfSound *) * 2);

    sounds[0] = sfSound_create();
    sfSound_setBuffer(sounds[0], \
    sfSoundBuffer_createFromFile("Rsrce/Nemesis_Footstep.ogg"));
    sounds[1] = sfSound_create();
    sfSound_setBuffer(sounds[1], \
    sfSoundBuffer_createFromFile("Rsrce/Bloodblade.ogg"));
    sfSound_setVolume(sounds[1], 60);
    return sounds;
}

boss_t *complete_param(boss_t *nemesis)
{
    nemesis->rect.height = 288;
    nemesis->rect.width = 288;
    nemesis->rect.left = 0;
    nemesis->coord.y = 3190;
    nemesis->coord.x = 1400;
    nemesis->rect.top = 0;
    return nemesis;
}

static projectile_t *assign_direction(projectile_t *projo)
{
    static int i = 0;

    if (i == 0) {
        projo->direction = DOWN;
        projo->rect.top = 0;
    }
    if (i == 1) {
        projo->direction = UP;
        projo->rect.top = 150;
    }
    if (i == 2) {
        projo->direction = LEFT;
        projo->rect.top = 300;
    }
    if (i == 3) {
        projo->direction = RIGHT;
        projo->rect.top = 450;
    }
    sfSprite_setTextureRect(projo->sprite, projo->rect);
    i = i + 1;
    return projo;
}

static projectile_t **create_projos(void)
{
    projectile_t **list_projos = malloc(sizeof(projectile_t *) * 4);
    int i = 0;

    while (i < 4) {
        list_projos[i] = malloc(sizeof(projectile_t));
        list_projos[i]->chrono_launch.clock = sfClock_create();
        list_projos[i]->chrono_anim.clock = sfClock_create();
        list_projos[i]->chrono_mov.clock = sfClock_create();
        list_projos[i]->coord.x = -1000;
        list_projos[i]->coord.y = -1000;
        list_projos[i]->rect.left = 0;
        list_projos[i]->rect.width = 150;
        list_projos[i]->rect.height = 150;
        list_projos[i]->launched = sfFalse;
        list_projos[i]->sprite = sfSprite_create();
        list_projos[i]->text =
        sfTexture_createFromFile("Rsrce/bloodblade.png", NULL);
        assign_direction(list_projos[i]);
        sfSprite_setPosition(list_projos[i]->sprite, list_projos[i]->coord);
        sfSprite_setTexture(list_projos[i]->sprite, list_projos[i]->text, sfFalse);
        i = i + 1;
    }
    return list_projos;
}


boss_t *create_nemesis(void)
{
    boss_t *nemesis = malloc(sizeof(boss_t));

    nemesis->text = sfTexture_createFromFile("Rsrce/Nemesis.png", NULL);
    nemesis->chrono_knockback.clock = sfClock_create();
    nemesis->chrono_sounds.clock = sfClock_create();
    nemesis->chrono_anim.clock = sfClock_create();
    nemesis->Chrono_wait.clock = sfClock_create();
    nemesis->chrono_jump.clock = sfClock_create();
    nemesis->chrono_mov.clock = sfClock_create();
    nemesis->list_projos = create_projos();
    nemesis->sprite = sfSprite_create();
    nemesis->sounds = create_sounds();
    nemesis->touched = sfFalse;
    nemesis = complete_param(nemesis);
    nemesis->dead = sfFalse;
    nemesis->state = IDLE;
    nemesis->life = 10;
    sfSprite_setPosition(nemesis->sprite, nemesis->coord);
    sfSprite_setTexture(nemesis->sprite, nemesis->text, sfFalse);
    sfSprite_setTextureRect(nemesis->sprite, nemesis->rect);
    return nemesis;
}

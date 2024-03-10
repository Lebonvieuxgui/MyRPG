/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** create_player
*/
#include "myrpg.h"

static sfSound **create_sounds(void)
{
    sfSound **sounds = malloc(sizeof(sfSound *) * 2);

    sounds[0] = sfSound_create();
    sfSound_setBuffer(sounds[0], \
    sfSoundBuffer_createFromFile("Rsrce/Player_Footstep.ogg"));
    sfSound_setVolume(sounds[0], 60);
    sounds[1] = sfSound_create();
    sfSound_setBuffer(sounds[1], \
    sfSoundBuffer_createFromFile("Rsrce/Sword.ogg"));
    sfSound_setVolume(sounds[1], 60);
    return sounds;
}

static player_t *complete_param(player_t *player)
{
    player->rect.height = 192;
    player->rect.width = 192;
    player->coord.x = -1500;
    player->coord.y = 400;
    player->rect.left = 0;
    player->rect.top = 1344;
    return player;
}

player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->text = sfTexture_createFromFile("Rsrce/Player.png", NULL);
    player->sprite = sfSprite_create();
    player->chrono_knockback.clock = sfClock_create();
    player->chrono_particles.clock = sfClock_create();
    player->chrono_sounds.clock = sfClock_create();
    player->chrono_skill.clock = sfClock_create();
    player->chrono_anim.clock = sfClock_create();
    player->chrono_dash.clock = sfClock_create();
    player->chrono_mov.clock = sfClock_create();
    player->sounds = create_sounds();
    player->ancient_direction = RIGHT;
    player = complete_param(player);
    player->direction = RIGHT;
    player->moved = sfFalse;
    player->block = sfFalse;
    player->dash = sfFalse;
    player->dead = sfFalse;
    player->state = MOVING;
    player->life = 6;
    player->list_particles = create_list_particles();
    sfSprite_setPosition(player->sprite, player->coord);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setTexture(player->sprite, player->text, sfFalse);
    return player;
}

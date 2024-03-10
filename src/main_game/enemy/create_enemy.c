/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** create_enemy
*/
#include "myrpg.h"

static sfSound **create_sounds(void)
{
    return NULL;
}

enemy_t **create_list_enemies(game_object_t *game)
{
    enemy_t **list_enemies = malloc(sizeof(enemy_t *) * game->nb_enemies);

    if (!list_enemies)
        return NULL;
    place_room1(list_enemies);
    place_room2(list_enemies);
    place_room3(list_enemies);
    place_room4(list_enemies);
    return list_enemies;
}

static projectile_t **create_rocks(void)
{
    projectile_t **list_rocks = malloc(sizeof(projectile_t *) * 10);
    int i = 0;

    while (i < 10) {
        list_rocks[i] = malloc(sizeof(projectile_t));
        list_rocks[i]->chrono_launch.clock = sfClock_create();
        list_rocks[i]->chrono_mov.clock = sfClock_create();
        list_rocks[i]->coord.x = -1000;
        list_rocks[i]->coord.y = -1000;
        list_rocks[i]->launched = sfFalse;
        list_rocks[i]->sprite = sfSprite_create();
        list_rocks[i]->text = sfTexture_createFromFile("Rsrce/rock.png", NULL);
        sfSprite_setPosition(list_rocks[i]->sprite, list_rocks[i]->coord);
        sfSprite_setTexture(list_rocks[i]->sprite, list_rocks[i]->text, sfFalse);
        i = i + 1;
    }
    return list_rocks;
}

enemy_t *create_slinger(int x, int y)
{
    enemy_t *slinger = malloc(sizeof(enemy_t));

    slinger->text = sfTexture_createFromFile("Rsrce/Slinger.png", NULL);
    slinger->chrono_knockback.clock = sfClock_create();
    slinger->chrono_sounds.clock = sfClock_create();
    slinger->chrono_anim.clock = sfClock_create();
    slinger->chrono_mov.clock = sfClock_create();
    slinger->sprite = sfSprite_create();
    slinger->touched = sfFalse;
    slinger->list_rocks = create_rocks();
    slinger->rect.height = 192;
    slinger->rect.width = 192;
    slinger->direction = DOWN;
    slinger->type = SLINGER;
    slinger->sounds = create_sounds();
    slinger->rect.left = 0;
    slinger->coord.y = y;
    slinger->coord.x = x;
    slinger->rect.top = 0;
    slinger->dead = sfFalse;
    slinger->state = IDLE;
    slinger->rock = 0;
    slinger->life = 3;
    sfSprite_setPosition(slinger->sprite, slinger->coord);
    sfSprite_setTexture(slinger->sprite, slinger->text, sfFalse);
    sfSprite_setTextureRect(slinger->sprite, slinger->rect);
    return slinger;
}

enemy_t *create_possesed(int x, int y)
{
    enemy_t *possesed = malloc(sizeof(enemy_t));

    possesed->text = sfTexture_createFromFile("Rsrce/Possesed.png", NULL);
    possesed->chrono_knockback.clock = sfClock_create();
    possesed->chrono_sounds.clock = sfClock_create();
    possesed->chrono_anim.clock = sfClock_create();
    possesed->chrono_mov.clock = sfClock_create();
    possesed->sprite = sfSprite_create();
    possesed->touched = sfFalse;
    possesed->list_rocks = NULL;
    possesed->rect.height = 192;
    possesed->rect.width = 192;
    possesed->direction = DOWN;
    possesed->type = POSSESED;
    possesed->sounds = create_sounds();
    possesed->rect.left = 0;
    possesed->coord.y = y;
    possesed->coord.x = x;
    possesed->rect.top = 0;
    possesed->dead = sfFalse;
    possesed->state = IDLE;
    possesed->life = 3;
    sfSprite_setPosition(possesed->sprite, possesed->coord);
    sfSprite_setTexture(possesed->sprite, possesed->text, sfFalse);
    sfSprite_setTextureRect(possesed->sprite, possesed->rect);
    return possesed;
}

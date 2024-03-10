/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** trajectory_projos
*/
#include "myrpg.h"

static projectile_t *trajectory_projo(game_object_t *game, projectile_t *projo)
{
    if (projo->direction == DOWN && collision_down_projo(game, projo) == 0)
        projo->coord.y = projo->coord.y + 13;
    if (projo->direction == UP && collision_up_projo(game, projo) == 0)
        projo->coord.y = projo->coord.y - 13;
    if (projo->direction == LEFT && collision_left_projo(game, projo) == 0)
        projo->coord.x = projo->coord.x - 13;
    if (projo->direction == RIGHT && collision_right_projo(game, projo) == 0)
        projo->coord.x = projo->coord.x + 13;
    sfSprite_setPosition(projo->sprite, projo->coord);
    return projo;
}

static player_t *touched_player_projos(projectile_t *projo,
player_t *player)
{
    if (player->state != DASHING) {
        if (projo->direction == UP) {
            player->rect.top = 2304;
            player->pushback = UP;
        }
        if (projo->direction == DOWN) {
            player->rect.top = 2496;
            player->pushback = DOWN;
        }
        if (projo->direction == RIGHT) {
            player->rect.top = 2688;
            player->pushback = RIGHT;
        }
        if (projo->direction == LEFT) {
            player->rect.top = 2880;
            player->pushback = LEFT;
        }
        player->rect.left = 0;
        player->state = HURT_NEMESIS;
        sfSprite_setTextureRect(player->sprite, player->rect);
    }
    return player;
}

static projectile_t *collision_projo(projectile_t *projo, player_t *player)
{
    if ((projo->coord.x + 75 > player->coord.x + 30
    && projo->coord.x + 75 < player->coord.x + 150)
    && (projo->coord.y + 75 > player->coord.y
    && projo->coord.y + 75 < player->coord.y + 160)
    && player->state != DASHING) {
        projo->coord.x = -1000;
        projo->coord.y = -1000;
        projo->launched = sfFalse;
        touched_player_projos(projo, player);
    }
    return projo;
}

static projectile_t *animation_projo(projectile_t *projo)
{
    projo->rect.left = projo->rect.left + 150;
    if (projo->rect.left > 580)
        projo->rect.left = 0;
    sfSprite_setTextureRect(projo->sprite, projo->rect);
    return projo;
}

boss_t *move_projos_nemesis(game_object_t *game, boss_t *nemesis,
player_t *player)
{
    int i = 0;

    while (i < 4) {
        nemesis->list_projos[i]->chrono_mov =
        get_chrono(nemesis->list_projos[i]->chrono_mov);
        if (nemesis->list_projos[i]->chrono_mov.seconds > 0.0000001
        && nemesis->list_projos[i]->launched == sfTrue) {
            trajectory_projo(game, nemesis->list_projos[i]);
            collision_projo(nemesis->list_projos[i], player);
            sfClock_restart(nemesis->list_projos[i]->
            chrono_mov.clock);
        }
        nemesis->list_projos[i]->chrono_anim =
        get_chrono(nemesis->list_projos[i]->chrono_anim);
        if (nemesis->list_projos[i]->chrono_anim.seconds > 0.05
        && nemesis->list_projos[i]->launched == sfTrue) {
            animation_projo(nemesis->list_projos[i]);
            sfClock_restart(nemesis->list_projos[i]->
            chrono_anim.clock);
        }
        i = i + 1;
    }
    return nemesis;
}

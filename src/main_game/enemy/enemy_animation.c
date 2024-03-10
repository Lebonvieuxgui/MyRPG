/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** enemy_animation
*/
#include "myrpg.h"

static enemy_t *change_frame_slinger(enemy_t *enemy, player_t *player)
{
    enemy->rect.left = enemy->rect.left + 192;
    if (enemy->state == IDLE) {
        if (enemy->rect.left > 1150)
            enemy->rect.left = 0;
    } else if (enemy->state == MOVING) {
        if (enemy->rect.left > 1150)
            enemy->rect.left = 0;
    } else if (enemy->state == ATTACKING) {
        if (enemy->rect.left > 1530) {
            enemy->rect.left = 0;
            return_idle_enemy(enemy, player);
        }
    } else if (enemy->state == DEAD) {
        if (enemy->rect.left > 1530)
            enemy->rect.left = 1344;
    }
    return enemy;
}

static enemy_t *change_frame_possesed(enemy_t *enemy, player_t *player)
{
    enemy->rect.left = enemy->rect.left + 192;
    if (enemy->state == IDLE) {
        if (enemy->rect.left > 900)
            enemy->rect.left = 0;
    } else if (enemy->state == MOVING) {
        if (enemy->rect.left > 1150)
            enemy->rect.left = 0;
    } else if (enemy->state == ATTACKING) {
        if (enemy->rect.left > 1150) {
            enemy->rect.left = 0;
            return_idle_enemy(enemy, player);
        }
    } else if (enemy->state == DEAD) {
        if (enemy->rect.left > 1150)
            enemy->rect.left = 960;
    }
    return enemy;
}

static enemy_t *choose_enemy_frame(enemy_t *enemy, player_t *player)
{
    if (enemy->type == POSSESED)
        change_frame_possesed(enemy, player);
    if (enemy->type == SLINGER)
        change_frame_slinger(enemy, player);
    return enemy;
}

enemy_t *return_idle_enemy(enemy_t *enemy, player_t *player)
{
    if (enemy->type == POSSESED) {
        if (attack_possesed(enemy, player) == 0)
            return enemy;
    } else if (enemy->type == POSSESED) {
        if (attack_slinger(enemy, player) == 0)
            return enemy;
    }
    enemy->state = IDLE;
    if (enemy->direction == DOWN)
        enemy->rect.top = 0;
    if (enemy->direction == UP)
        enemy->rect.top = 192;
    if (enemy->direction == LEFT)
        enemy->rect.top = 384;
    if (enemy->direction == RIGHT)
        enemy->rect.top = 576;
    return enemy;
}

enemy_t **enemy_animation(game_object_t *game, enemy_t **list_enemy,
player_t *player, int nb_enemys)
{
    float timer = 0.15;
    int i = 0;

    if (list_enemy[i]->state == DEAD)
        timer = 0.3;
    while (i < nb_enemys) {
        list_enemy[i]->chrono_anim = \
        get_chrono(list_enemy[i]->chrono_anim);
        if (list_enemy[i]->chrono_anim.seconds > timer) {
            choose_enemy_frame(list_enemy[i], player);
            sfSprite_setTextureRect(list_enemy[i]->sprite,
            list_enemy[i]->rect);
            sfClock_restart(list_enemy[i]->chrono_anim.clock);
        }
        knockback_enemy(game, list_enemy[i], player);
        i = i + 1;
        timer = 0.2;
    }
    return list_enemy;
}

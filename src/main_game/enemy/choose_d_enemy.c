/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** choose_d_enemy
*/
#include "myrpg.h"

static enemy_t *direction_possesed(enemy_t *enemy, player_t *player)
{
    if (enemy->coord.x >= player->coord.x - 10
    && enemy->coord.x <= player->coord.x + 10) {
        if (enemy->coord.y < player->coord.y) {
            enemy->direction = DOWN;
            enemy->rect.top = 768;
        } else {
            enemy->direction = UP;
            enemy->rect.top = 960;
        }
    } else {
        if (enemy->coord.x > player->coord.x) {
            enemy->direction = LEFT;
            enemy->rect.top = 1152;
        } else {
            enemy->direction = RIGHT;
            enemy->rect.top = 1344;
        }
    }
    return enemy;
}

static enemy_t *direction_slinger(enemy_t *enemy, player_t *player)
{
    if ((enemy->coord.x >= player->coord.x - 10
    && enemy->coord.x <= player->coord.x + 10)) {
        if (enemy->coord.y < player->coord.y) {
            enemy->direction = DOWN;
            enemy->rect.top = 768;
        } else {
            enemy->direction = UP;
            enemy->rect.top = 960;
        }
    } else {
        if (enemy->coord.x > player->coord.x) {
            enemy->direction = LEFT;
            enemy->rect.top = 1152;
        } else {
            enemy->direction = RIGHT;
            enemy->rect.top = 1344;
        }
    }
    return enemy;
}

enemy_t *choose_direction_enemy(enemy_t *enemy, player_t *player)
{
    if (enemy->type == POSSESED)
        direction_possesed(enemy, player);
    if (enemy->type == SLINGER)
        direction_slinger(enemy, player);
    return enemy;
}

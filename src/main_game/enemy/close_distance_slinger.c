/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** close_distance_slinger
*/
#include "myrpg.h"

static enemy_t *close_distance_vertical(game_object_t *game,
enemy_t *enemy, player_t *player)
{
    if (enemy->coord.y < player->coord.y) {
        if (enemy->coord.x == player->coord.x &&
        (collision_down_enemy(game, enemy) == 0))
            enemy->coord.y = enemy->coord.y + 3;
        else if (collision_down_enemy(game,enemy) == 0)
            enemy->coord.y = enemy->coord.y + 2;
    }
    if (enemy->coord.y > player->coord.y) {
        if (enemy->coord.x == player->coord.x &&
        (collision_up_enemy(game, enemy) == 0))
            enemy->coord.y = enemy->coord.y - 3;
        else if (collision_up_enemy(game,enemy) == 0)
            enemy->coord.y = enemy->coord.y - 2;
    }
    return enemy;
}

enemy_t *close_distance_slinger(game_object_t *game,
enemy_t *enemy, player_t *player)
{
    close_distance_vertical(game, enemy, player);
    if ((enemy->coord.x < player->coord.x + 800
    && enemy->coord.x > player->coord.x)) {
        if (enemy->coord.y == player->coord.y &&
        (collision_left_enemy(game, enemy) == 0))
            enemy->coord.x = enemy->coord.x + 3;
        else if (collision_left_enemy(game,enemy) == 0)
            enemy->coord.x = enemy->coord.x + 2;
    }
    if ((enemy->coord.x > player->coord.x - 800
    && enemy->coord.x < player->coord.x)) {
        if (enemy->coord.y == player->coord.y &&
        (collision_left_enemy(game, enemy) == 0))
            enemy->coord.x = enemy->coord.x - 3;
        else if (collision_left_enemy(game,enemy) == 0)
            enemy->coord.x = enemy->coord.x - 2;
    }
    return enemy;
}


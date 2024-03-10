/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** detect_attack
*/
#include "myrpg.h"

static enemy_t *check_attack(enemy_t *enemy, player_t *player)
{
    if (attack_range(enemy, player) == 0 && enemy->state != DEAD
    && enemy->dead == sfFalse)
        touched_enemy(enemy, player);
    return enemy;
}

enemy_t **detect_attack_player(enemy_t **list_enemys, player_t *player,
int nb_enemys)
{
    int i = 0;

    if (player->state == ATTACKING && player->rect.left == 384)
        while (i < nb_enemys) {
            check_attack(list_enemys[i], player);
            i = i + 1;
        }
    return list_enemys;
}

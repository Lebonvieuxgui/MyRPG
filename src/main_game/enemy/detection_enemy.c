/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** detection_enemy
*/
#include "myrpg.h"

int detect_player(enemy_t *enemy, player_t *player)
{
    if (enemy->type == POSSESED)
        if (player->coord.x > enemy->coord.x - 400
        && player->coord.x < enemy->coord.x + 400
        && player->coord.y > enemy->coord.y - 400
        && player->coord.y < enemy->coord.y + 400)
            return 0;
    if (enemy->type == SLINGER)
        if (player->coord.x > enemy->coord.x - 1200
        && player->coord.x < enemy->coord.x + 1200
        && player->coord.y > enemy->coord.y - 1200
        && player->coord.y < enemy->coord.y + 1200)
            return 0;
    return 1;
}

enemy_t **lose_focus(enemy_t **list_enemys, player_t *player, int nb_enemys)
{
    int i = 0;

    while (i < nb_enemys) {
        if (detect_player(list_enemys[i], player ) == 1
        && list_enemys[i]->state != DEAD)
            return_idle_enemy(list_enemys[i], player);
        i = i + 1;
    }
    return list_enemys;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** death_enemy
*/
#include "myrpg.h"

static enemy_t *change_death_frame(enemy_t *enemy)
{
    if (enemy->direction == DOWN)
        enemy->rect.top = 3072;
    if (enemy->direction == UP)
        enemy->rect.top = 3264;
    if (enemy->direction == LEFT)
        enemy->rect.top = 3456;
    if (enemy->direction == RIGHT)
        enemy->rect.top = 3648;
    return enemy;
}

enemy_t **death_enemy(game_object_t *game, enemy_t **list_enemys,
int nb_enemys)
{
    int i = 0;

    while (i < nb_enemys) {
        if (list_enemys[i]->life == 0) {
            list_enemys[i]->dead = sfTrue;
            list_enemys[i]->state = DEAD;
            list_enemys[i]->life = -1;
            change_death_frame(list_enemys[i]);
            drop_heart(list_enemys[i], game->heart, i);
            list_enemys[i]->rect.left = 0;
        }
        i = i + 1;
    }
    return list_enemys;
}

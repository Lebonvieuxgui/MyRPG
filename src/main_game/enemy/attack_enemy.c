/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** attack_enemy
*/
#include "myrpg.h"

player_t *detect_attack_enemy(enemy_t **list_enemys,
player_t *player, int nb_enemys)
{
    int i = 0;

    while (i < nb_enemys) {
        if (list_enemys[i]->type == POSSESED)
            attack_possesed(list_enemys[i], player);
        if (list_enemys[i]->type == SLINGER)
            attack_slinger(list_enemys[i], player);
        if (list_enemys[i]->type == POSSESED
        && list_enemys[i]->state == ATTACKING
        && list_enemys[i]->rect.left == 768 && player->state != DASHING
        && player->state != BLOCKED)
            if (attack_range_possesed(player, list_enemys[i]) == 0) {
                touched_player(list_enemys[i], player);
            }
        i = i + 1;
    }
    return player;
}

enemy_t *attack_slinger(enemy_t *enemy, player_t *player)
{
    if (in_range_for_slinger(enemy, player) == 0 && enemy->state != ATTACKING
    && enemy->state != HURT && enemy->state != DEAD &&
    player->dead == sfFalse) {
        enemy->state = ATTACKING;
        enemy->rect.left = 0;
        if (enemy->direction == DOWN)
            enemy->rect.top = 1536;
        if (enemy->direction == UP)
            enemy->rect.top = 1728;
        if (enemy->direction == LEFT)
            enemy->rect.top = 1920;
        if (enemy->direction == RIGHT)
            enemy->rect.top = 2112;
        sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    }
    return enemy;
}

enemy_t *attack_possesed(enemy_t *enemy, player_t *player)
{
    if (in_range_for_possesed(enemy, player) == 0 && enemy->state != ATTACKING
    && enemy->state != HURT && enemy->state != DEAD &&
    player->dead == sfFalse) {
        enemy->state = ATTACKING;
        enemy->rect.left = 0;
        if (enemy->direction == DOWN)
            enemy->rect.top = 1536;
        if (enemy->direction == UP)
            enemy->rect.top = 1728;
        if (enemy->direction == LEFT)
            enemy->rect.top = 1920;
        if (enemy->direction == RIGHT)
            enemy->rect.top = 2112;
        sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    }
    return enemy;
}

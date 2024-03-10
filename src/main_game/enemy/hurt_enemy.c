/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** hurt_enemy
*/
#include "myrpg.h"

enemy_t **reduce_life_enemy(enemy_t **list_enemys, int nb_enemys)
{
    int i = 0;

    while (i < nb_enemys) {
        if (list_enemys[i]->state == HURT && list_enemys[i]->touched == 0) {
            list_enemys[i]->life = list_enemys[i]->life - 1;
            list_enemys[i]->touched = sfTrue;
        }
        if (list_enemys[i]->state == IDLE)
            list_enemys[i]->touched = sfFalse;
        i = i + 1;
    }
    return list_enemys;
}

enemy_t *touched_enemy(enemy_t *enemy, player_t *player)
{
    if (player->direction == UP)
        enemy->rect.top = 2304;
    if (player->direction == DOWN)
        enemy->rect.top = 2496;
    if (player->direction == RIGHT)
        enemy->rect.top = 2688;
    if (player->direction == LEFT)
        enemy->rect.top = 2880;
    enemy->rect.left = 0;
    enemy->state = HURT;
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    return enemy;
}

static enemy_t *move_knockback(game_object_t *game,
enemy_t *enemy, player_t *player)
{
    if (player->direction == DOWN && collision_down_enemy(game, enemy) == 0)
        enemy->coord.y = enemy->coord.y + 4;
    if (player->direction == UP && collision_up_enemy(game, enemy) == 0)
        enemy->coord.y = enemy->coord.y - 4;
    if (player->direction == LEFT && collision_left_enemy(game, enemy) == 0)
        enemy->coord.x = enemy->coord.x - 4;
    if (player->direction == RIGHT && collision_right_enemy(game, enemy) == 0)
        enemy->coord.x = enemy->coord.x + 4;
    if (enemy->rect.left > 570) {
        enemy->rect.left = 0;
        return_idle_enemy(enemy, player);
    }
    return enemy;
}

enemy_t *knockback_enemy(game_object_t *game, enemy_t *enemy, player_t *player)
{
    enemy->chrono_knockback = get_chrono(enemy->chrono_knockback);
    if ((enemy->state == HURT)
    && enemy->chrono_knockback.seconds > 0.000001) {
        move_knockback(game, enemy, player);
        sfClock_restart(enemy->chrono_knockback.clock);
    }
    sfSprite_setPosition(player->sprite, player->coord);

    return enemy;
}

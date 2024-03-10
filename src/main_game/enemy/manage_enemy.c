/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** manage_enemy
*/
#include "myrpg.h"

static enemy_t *check_range(enemy_t *enemy, player_t *player,
game_object_t *game)
{
    if ((enemy->coord.x != player->coord.x
    || enemy->coord.y != player->coord.y)
    && enemy->state != HURT && enemy->state != DEAD
    && enemy->state != ATTACKING && player->dead == sfFalse
    && detect_player(enemy, player) == 0)
        close_distance(game, enemy, player);
    sfSprite_setPosition(enemy->sprite, enemy->coord);
    sfClock_restart(enemy->chrono_mov.clock);
    return enemy;
}

enemy_t **manage_enemy(enemy_t **list_enemy, player_t *player, int nb_enemys,
game_object_t *game)
{
    int i = 0;

    while (i < nb_enemys) {
        list_enemy[i]->chrono_mov = get_chrono(list_enemy[i]->chrono_mov);
        if (list_enemy[i]->chrono_mov.seconds > 0.0000001) {
            check_range(list_enemy[i], player, game);
        }
        i = i + 1;
    }
    return list_enemy;
}

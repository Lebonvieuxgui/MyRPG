/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** sounds_enemy
*/
#include "myrpg.h"

static void check_sounds(enemy_t *enemy)
{
    enemy->chrono_sounds = get_chrono(enemy->chrono_sounds);
    if (enemy->chrono_sounds.seconds > 0.2) {
        if (enemy->rect.top > 1530 && enemy->rect.top < 2300
        && ((enemy->rect.left > 0 && enemy->rect.left < 960))
        && enemy->type == SLINGER) {
            sfSound_play(enemy->sounds[0]);
            sfClock_restart(enemy->chrono_sounds.clock);
        }
    }
}

enemy_t **sounds_enemies(enemy_t **list_enemies, int nb_enemies)
{
    int i = 0;

    while (i < nb_enemies) {
        check_sounds(list_enemies[i]);
        i = i + 1;
    }
    return list_enemies;
}

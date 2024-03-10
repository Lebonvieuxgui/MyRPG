/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** gest_diplay
*/

#include "myrpg.h"

static void check_rock(game_object_t *game, enemy_t *enemy)
{
    int i = 0;

    while (i < 10) {
        if (enemy->list_rocks[i]->launched == sfTrue) {
            sfRenderWindow_drawSprite(game->window->w,
            enemy->list_rocks[i]->sprite, NULL);
        }
        i = i + 1;
    }
}

void display_rocks(game_object_t *game, enemy_t **list_enemies, int nb_enemies)
{
    int i = 0;

    while (i < nb_enemies) {
        if (list_enemies[i]->type == SLINGER)
            check_rock(game, list_enemies[i]);
        i = i + 1;
    }
}

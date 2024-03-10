/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** destroy_music
*/

#include "myrpg.h"

void destroy_music(game_object_t *game, boss_t *nemesis, player_t *player)
{
    if (!game)
        return;
    sfMusic_destroy(game->gamesong);
    sfSound_destroy(nemesis->sounds[0]);
    sfSound_destroy(player->sounds[0]);
    for (int i = 0; game->heart[i] != NULL; i++)
        sfSound_destroy(game->heart[i]->sounds[0]);
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** player_boss
*/
#include "myrpg.h"

game_object_t *player_boss(game_object_t *game)
{
    movement_player(game);
    player_end(game->player);
    dash_animation(game, game->player);
    knockback_player(game, game->player);
    knockback_block(game, game->player);
    walking_particles(game->player);
    player_animation(game->player, game);
    reduce_life_player(game->player);
    detect_attack_player_nemesis(game->nemesis, game->player);
    sounds_player(game->player);
    return game;
}

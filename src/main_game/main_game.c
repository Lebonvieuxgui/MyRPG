/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** main_game
*/
#include "myrpg.h"

static game_object_t *main_game_bis(game_object_t *game)
{
    taked_keys(game);
    taked_objects(game->objects, game->player);
    key_green_animation(game->objects[1]);
    key_blue_animation(game->objects[2]);
    key_yellow_animation(game->objects[3]);
    key_red_animation(game->objects[4]);
    medal_animation(game->objects[0]);
    medal_animation(game->objects[5]);
    return game;
}

game_object_t *main_game(game_object_t *game)
{
    main_game_bis(game);
    manage_enemy(game->list_enemies, game->player, game->nb_enemies, game);
    movement_player(game);
    block_player(game->player);
    player_end(game->player);
    dash_animation(game, game->player);
    knockback_player(game, game->player);
    player_animation(game->player, game);
    walking_particles(game->player);
    knockback_block(game, game->player);
    enemy_animation(game, game->list_enemies, game->player, game->nb_enemies);
    //sounds_enemies(game->list_enemies, game->nb_enemies);
    reduce_life_enemy(game->list_enemies, game->nb_enemies);
    reduce_life_player(game->player);
    death_enemy(game, game->list_enemies, game->nb_enemies);
    detect_attack_enemy(game->list_enemies, game->player, game->nb_enemies);
    manage_rocks(game, game->list_enemies, game->player, game->nb_enemies);
    detect_attack_player(game->list_enemies, game->player, game->nb_enemies);
    sounds_player(game->player);
    lose_focus(game->list_enemies, game->player, game->nb_enemies);
    return game;
}

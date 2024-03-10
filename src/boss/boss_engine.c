/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** boss_engine
*/
#include "myrpg.h"

static game_object_t *change_game(game_object_t *game)
{
    if (game->player->coord.x > 2830 && game->player->coord.y > 3240
    && game->GAMESTATE != GAME) {
        sfMusic_destroy(game->gamesong);
        game->gamesong = sfMusic_createFromFile("Rsrce/catacombs.ogg");
        game->GAMESTATE = GAME;
        sfMusic_setLoop(game->gamesong, sfTrue);
        sfMusic_setVolume(game->gamesong, game->volume_music);
        sfMusic_play(game->gamesong);
    }
    return game;
}

game_object_t *boss_engine(game_object_t *game)
{
    sfRenderWindow_clear(game->window->w, sfBlack);
    sfRenderWindow_setMouseCursorVisible(game->window->w, sfFalse);
    change_game(game);
    manage_event(game);
    player_boss(game);
    block_player(game->player);
    move_nemesis(game, game->nemesis, game->player);
    detect_attack_nemesis(game->nemesis, game->player);
    wait_jump_nemesis(game->nemesis);
    wait_jumpjo_nemesis(game->nemesis);
    wait_jumptack_nemesis(game->nemesis);
    knockback_nemesis(game->nemesis, game->player);
    jump_nemesis_animation(game->nemesis);
    jumpjo_nemesis_animation(game->nemesis, game->player);
    jumptack_nemesis_animation(game->nemesis, game->player);
    move_projos_nemesis(game, game->nemesis, game->player);
    animation_nemesis(game->nemesis);
    lose_focus_nemesis(game->nemesis, game->player);
    reduce_life_nemesis(game->nemesis);
    death_nemesis(game->nemesis);
    sounds_nemesis(game->nemesis);
    gest_view(game);
    sfRenderWindow_display(game->window->w);
    return game;
}

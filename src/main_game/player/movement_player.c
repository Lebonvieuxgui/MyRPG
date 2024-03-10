/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** movement_player
*/
#include "myrpg.h"

static void condition_movement(game_object_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)
    && (collision_down(game, 50, -30) == 0))
        down_direction(game->player);
    if (sfKeyboard_isKeyPressed(sfKeyUp)
    && (collision_up(game, 50, -180) == 0))
        up_direction(game->player);
    if (sfKeyboard_isKeyPressed(sfKeyLeft)
    && (collision_left(game, 40, -43) == 0))
        left_direction(game->player);
    if (sfKeyboard_isKeyPressed(sfKeyRight)
    && (collision_right(game, 150, -43) == 0))
        right_direction(game->player);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        attack_player(game->player);
    if (game->player->moved == sfFalse && game->player->state == MOVING)
        player_stop(game->player);
}

player_t *movement_player(game_object_t *game)
{
    game->player->moved = sfFalse;
    game->player->chrono_mov = get_chrono(game->player->chrono_mov);
    if (game->player->chrono_mov.seconds > 0.00001 && (game->player->state == MOVING
    || game->player->state == IDLE) && game->player->dead == sfFalse ) {
        condition_movement(game);
        dash_player(game->player);
        sfClock_restart(game->player->chrono_mov.clock);
    }
    return game->player;
}

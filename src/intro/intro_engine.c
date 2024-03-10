/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** intro_engine
*/
#include "myrpg.h"

static player_t *intro_movement(player_t *player)
{
    player->moved = sfFalse;
    player->chrono_mov = get_chrono(player->chrono_mov);
    if (player->chrono_mov.seconds > 0.00001 && (player->state == MOVING
    || player->state == IDLE) && player->dead == sfFalse ) {
        player->coord.x = player->coord.x + 4;
        sfSprite_setPosition(player->sprite, player->coord);
        sfClock_restart(player->chrono_mov.clock);
    }

    return player;
}

game_object_t *intro_engine(game_object_t *game)
{
    intro_movement(game->player);
    player_animation(game->player, game);
    walking_particles(game->player);
    sounds_player(game->player);
    sfRenderWindow_clear(game->window->w, sfBlack);
    sfRenderWindow_setMouseCursorVisible(game->window->w, sfFalse);
    manage_event(game);
    gest_view(game);
    sfRenderWindow_display(game->window->w);
    if (game->player->coord.x >= 300)
        game->GAMESTATE = GAME;
    return game;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** move_nemesis
*/
#include "myrpg.h"

static boss_t *close_distance_vertical(game_object_t *game,
boss_t *nemesis, player_t *player)
{
    if (nemesis->coord.y < player->coord.y - 80) {
        if (nemesis->coord.x == player->coord.x &&
        (collision_down_nemesis(game, nemesis) == 0))
            nemesis->coord.y = nemesis->coord.y + 10;
        else if (collision_down_nemesis(game, nemesis) == 0)
            nemesis->coord.y = nemesis->coord.y + 4;
    }
    if (nemesis->coord.y > player->coord.y - 50) {
        if (nemesis->coord.x == player->coord.x &&
        (collision_up_nemesis(game, nemesis) == 0))
            nemesis->coord.y = nemesis->coord.y - 10;
        else if (collision_up_nemesis(game, nemesis) == 0)
            nemesis->coord.y = nemesis->coord.y - 4;
    }
    return nemesis;
}

static boss_t *close_distance_horizontal(game_object_t *game,
boss_t *nemesis, player_t *player)
{
    if (nemesis->coord.x > player->coord.x - 50) {
        if (nemesis->coord.y == player->coord.y &&
        (collision_left_nemesis(game, nemesis) == 0))
            nemesis->coord.x = nemesis->coord.x - 10;
        else if (collision_left_nemesis(game, nemesis) == 0)
            nemesis->coord.x = nemesis->coord.x - 4;
    }
    if (nemesis->coord.x < player->coord.x - 50) {
        if (nemesis->coord.y == player->coord.y &&
        (collision_right_nemesis(game, nemesis) == 0))
            nemesis->coord.x = nemesis->coord.x + 10;
        else if (collision_right_nemesis(game, nemesis) == 0)
            nemesis->coord.x = nemesis->coord.x + 4;
    }
    return nemesis;
}

static boss_t *close_distance_nemesis(game_object_t *game,
boss_t *nemesis, player_t *player)
{
    close_distance_vertical(game, nemesis, player);
    close_distance_horizontal(game, nemesis, player);
    choose_direction_nemesis(nemesis, player);
    nemesis->state = MOVING;
    return nemesis;
}

boss_t *move_nemesis(game_object_t *game, boss_t *nemesis, player_t *player)
{
    nemesis->chrono_mov = get_chrono(nemesis->chrono_mov);
    if (nemesis->chrono_mov.seconds > 0.0000001) {
        if ((nemesis->coord.x != player->coord.x
        || nemesis->coord.y != player->coord.y)
        && (nemesis->state == IDLE || nemesis->state == MOVING)
        && player->dead == sfFalse
        && detect_player_nemesis(nemesis, player) == 0)
            close_distance_nemesis(game, nemesis, player);
        sfSprite_setPosition(nemesis->sprite, nemesis->coord);
        sfClock_restart(nemesis->chrono_mov.clock);
    }
    return nemesis;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** knockback_block
*/
#include "myrpg.h"

static player_t *move_knockback(game_object_t *game, player_t *player)
{
    int knockback = 5;
    static int i = 0;

    if (player->state == BLOCKED_NEMESIS)
        knockback = 10;
    if (player->pushback == DOWN && collision_down(game, 50, 50) == 0)
        player->coord.y = player->coord.y + knockback;
    if (player->pushback == UP && collision_up(game, 50, -100) == 0)
        player->coord.y = player->coord.y - knockback;
    if (player->pushback == LEFT && collision_left(game, -40, -43) == 0)
        player->coord.x = player->coord.x - knockback;
    if (player->pushback == RIGHT && collision_right(game, 75, -43) == 0)
        player->coord.x = player->coord.x + knockback;
    sfSprite_setPosition(player->sprite, player->coord);
    i = i + 1;
    if (i == 10) {
        i = 0;
        return_idle(player);
    }
    return player;
}

player_t *knockback_block(game_object_t *game, player_t *player)
{
    player->chrono_knockback = get_chrono(player->chrono_knockback);
    if (((player->state == BLOCKED || player->state == BLOCKED_NEMESIS)
    && player->dead == sfFalse)
    && player->chrono_knockback.seconds > 0.000001) {
        move_knockback(game, player);
        sfClock_restart(player->chrono_knockback.clock);
    }
    sfSprite_setPosition(player->sprite, player->coord);
    return player;
}

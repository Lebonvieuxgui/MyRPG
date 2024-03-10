/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** block_player
*/
#include "myrpg.h"

static player_t *set_pushback(player_t *player, boss_t *nemesis)
{
    if (nemesis->direction == UP) {
        player->pushback = UP;
    }
    if (nemesis->direction == DOWN) {
        player->pushback = DOWN;
    }
    if (nemesis->direction == RIGHT) {
        player->pushback = RIGHT;
    }
    if (nemesis->direction == LEFT) {
        player->pushback = LEFT;
    }
    return player;
}

int is_blocked_nemesis(player_t *player, boss_t *nemesis)
{
    if (player->state == IDLE || player->state == MOVING
    || nemesis->state == ZONETACK) {
        return 0;
    } else if ((player->direction == DOWN && nemesis->direction != UP)
    || (player->direction == UP && nemesis->direction != DOWN)
    || (player->direction == LEFT && nemesis->direction != RIGHT)
    || (player->direction == RIGHT && nemesis->direction != LEFT)) {
        return 0;
    }
    set_pushback(player, nemesis);
    player->state = BLOCKED_NEMESIS;
    return 1;
}

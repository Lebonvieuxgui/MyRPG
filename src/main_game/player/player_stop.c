/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** player_stop
*/
#include "myrpg.h"

player_t *player_stop(player_t *player)
{
    if ((player->state != HURT || player->state != DEAD
    || player->state != ATTACKING) && player->dead == sfFalse) {
        if (player->direction == RIGHT)
            stop_right(player);
        if (player->direction == LEFT)
            stop_left(player);
        if (player->direction == UP)
            stop_up(player);
        if (player->direction == DOWN)
            stop_down(player);
    }
    return player;
}

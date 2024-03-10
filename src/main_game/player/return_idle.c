/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** return_idle
*/
#include "myrpg.h"

player_t *return_idle(player_t *player)
{
    if (player->state != DEAD && player->dead == sfFalse) {
        player->state = IDLE;
        if (player->direction == DOWN)
            player->rect.top = 0;
        if (player->direction == UP)
            player->rect.top = 192;
        if (player->direction == LEFT)
            player->rect.top = 384;
        if (player->direction == RIGHT)
            player->rect.top = 576;
    }
    return player;
}

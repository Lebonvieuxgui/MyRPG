/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** zonetack_nemesis
*/
#include "myrpg.h"

int zonetack_nemesis(boss_t *nemesis, player_t *player)
{
    if (nemesis->rect.left < 1150) {
        if ((player->coord.x > nemesis->coord.x - 100
        && player->coord.x < nemesis->coord.x + 150)
        && (player->coord.y > nemesis->coord.y - 150
        && player->coord.y < nemesis->coord.y + 150)
        && nemesis->state == JUMPTACK && nemesis->state != WAITING
        && nemesis->state != WAITING_JUMPTACK)
        return 0;
    }
    return 1;
}

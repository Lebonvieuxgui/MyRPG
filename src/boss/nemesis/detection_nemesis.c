/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** detection_nemesis
*/
#include "myrpg.h"

int detect_player_nemesis(boss_t *nemesis, player_t *player)
{
    if (player->coord.x > nemesis->coord.x - 1000
    && player->coord.x < nemesis->coord.x + 1000
    && player->coord.y > nemesis->coord.y - 1000
    && player->coord.y < nemesis->coord.y + 1000)
        return 0;
    return 1;
}

boss_t *lose_focus_nemesis(boss_t *nemesis, player_t *player)
{
    if (detect_player_nemesis(nemesis, player ) == 1
    && (nemesis->state == IDLE || nemesis->state == MOVING)
    && player->dead == sfFalse)
        return_idle_nemesis(nemesis);
    return nemesis;
}

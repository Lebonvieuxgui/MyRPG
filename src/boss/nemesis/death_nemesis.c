/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** death_nemesis
*/
#include "myrpg.h"

static boss_t *change_death_frame(boss_t *nemesis)
{
    if (nemesis->direction == DOWN)
        nemesis->rect.top = 4608;
    if (nemesis->direction == UP)
        nemesis->rect.top = 4896;
    if (nemesis->direction == LEFT)
        nemesis->rect.top = 5184;
    if (nemesis->direction == RIGHT)
        nemesis->rect.top = 8472;
    return nemesis;
}

boss_t *death_nemesis(boss_t *nemesis)
{
    if (nemesis->life == 0) {
        nemesis->dead = sfTrue;
        nemesis->state = DEAD;
        nemesis->life = -1;
        change_death_frame(nemesis);
        nemesis->rect.left = 0;
    }
    return nemesis;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-130-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** calculate_trajectory
*/
#include "myrpg.h"

int jump_right(boss_t *nemesis, sfVector2f goal)
{
    if (nemesis->coord.x != goal.x - 40) {
        if (nemesis->coord.x < goal.x - 40)
            nemesis->coord.x = nemesis->coord.x + 6;
        if (nemesis->coord.x > goal.x - 40)
            nemesis->coord.x = nemesis->coord.x - 6;
    }
    if (nemesis->coord.y != goal.y - 80) {
        if (nemesis->coord.y < goal.y - 80)
            nemesis->coord.y = nemesis->coord.y + 3;
        if (nemesis->coord.y > goal.y - 80)
            nemesis->coord.y = nemesis->coord.y - 3;
    }
    if ((nemesis->coord.x >= goal.x - 140
    && nemesis->coord.x <= goal.x + 40)
    && (nemesis->coord.y >= goal.y - 120
    && nemesis->coord.y <= goal.y))
        return 0;
    return 1;
}

int jump_left(boss_t *nemesis, sfVector2f goal)
{
    if (nemesis->coord.x != goal.x - 40) {
        if (nemesis->coord.x < goal.x - 40)
            nemesis->coord.x = nemesis->coord.x + 6;
        if (nemesis->coord.x > goal.x - 40)
            nemesis->coord.x = nemesis->coord.x - 6;
    }
    if (nemesis->coord.y != goal.y - 80) {
        if (nemesis->coord.y < goal.y - 80)
            nemesis->coord.y = nemesis->coord.y + 3;
        if (nemesis->coord.y > goal.y - 80)
            nemesis->coord.y = nemesis->coord.y - 3;
    }
    if ((nemesis->coord.x >= goal.x - 140
    && nemesis->coord.x <= goal.x + 40)
    && (nemesis->coord.y >= goal.y - 120
    && nemesis->coord.y <= goal.y))
        return 0;
    return 1;
}

int jump_up(boss_t *nemesis, sfVector2f goal)
{
    if (nemesis->coord.x != goal.x - 40) {
        if (nemesis->coord.x < goal.x - 40)
            nemesis->coord.x = nemesis->coord.x + 3;
        if (nemesis->coord.x > goal.x - 40)
            nemesis->coord.x = nemesis->coord.x - 3;
    }
    if (nemesis->coord.y != goal.y - 80) {
        if (nemesis->coord.y < goal.y - 80)
            nemesis->coord.y = nemesis->coord.y + 6;
        if (nemesis->coord.y > goal.y - 80)
            nemesis->coord.y = nemesis->coord.y - 6;
    }
    if ((nemesis->coord.x >= goal.x - 140
    && nemesis->coord.x <= goal.x + 40)
    && (nemesis->coord.y >= goal.y - 120
    && nemesis->coord.y <= goal.y))
        return 0;
    return 1;
}

int jump_down(boss_t *nemesis, sfVector2f goal)
{
    if (nemesis->coord.x != goal.x - 40) {
        if (nemesis->coord.x < goal.x - 40)
            nemesis->coord.x = nemesis->coord.x + 3;
        if (nemesis->coord.x > goal.x - 40)
            nemesis->coord.x = nemesis->coord.x - 3;
    }
    if (nemesis->coord.y != goal.y - 80) {
        if (nemesis->coord.y < goal.y - 80)
            nemesis->coord.y = nemesis->coord.y + 6;
        if (nemesis->coord.y > goal.y - 80)
            nemesis->coord.y = nemesis->coord.y - 6;
    }
    if ((nemesis->coord.x >= goal.x - 140
    && nemesis->coord.x <= goal.x + 40)
    && (nemesis->coord.y >= goal.y - 120
    && nemesis->coord.y <= goal.y))
        return 0;
    return 1;
}

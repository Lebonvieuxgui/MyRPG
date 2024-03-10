/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** jump_trajectory
*/
#include "myrpg.h"

static int jump_vertical(boss_t *nemesis, sfVector2f goal, int finish)
{
    if (nemesis->direction == DOWN) {
        if (jump_down(nemesis, goal) == 0 && finish == 0) {
            return 1;
        }
        if (jump_down(nemesis, goal) == 0 && finish == 1)
            return 2;
    }
    if (nemesis->direction == UP) {
        if (jump_up(nemesis, goal) == 0 && finish == 0) {
            return 1;
        }
        if (jump_up(nemesis, goal) == 0 && finish == 1)
            return 2;
    }
    if (finish == 1)
        return 1;
    if (finish == 2)
        return 2;
    return 0;
}

static int jump_horizontal(boss_t *nemesis, sfVector2f goal, int finish)
{
    if (nemesis->direction == LEFT) {
        if (jump_left(nemesis, goal) == 0 && finish == 0) {
            return 1;
        }
        if (jump_left(nemesis, goal) == 0 && finish == 1)
            return 2;
    }
    if (nemesis->direction == RIGHT) {
        if (jump_right(nemesis, goal) == 0 && finish == 0) {
            return 1;
        }
        if (jump_right(nemesis, goal) == 0 && finish == 1)
            return 2;
    }
    if (finish == 1)
        return 1;
    if (finish == 2)
        return 2;
    return 0;
}

int jump_trajectory(boss_t *nemesis, sfVector2f goal)
{
    static int finish = 0;

    if (finish == 2) {
        finish = 0;
        return 0;
    }
    finish = jump_vertical(nemesis, goal, finish);
    finish = jump_horizontal(nemesis, goal, finish);
    sfSprite_setPosition(nemesis->sprite, nemesis->coord);
    return 1;
}

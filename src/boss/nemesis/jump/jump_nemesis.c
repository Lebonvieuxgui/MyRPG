/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** jump_nemesis
*/
#include "myrpg.h"

static boss_t *launch_jump(boss_t *nemesis)
{
    sfVector2f goal;

    if (nemesis->direction == DOWN) {
        goal.x = 1300;
        goal.y = 2500;
        if (jump_trajectory(nemesis, goal) == 0) {
            nemesis->state = WAITING_JUMPTACK;
        }
    }
    if (nemesis->direction == UP) {
        goal.x = 1300;
        goal.y = 3880;
        if (jump_trajectory(nemesis, goal) == 0) {
            nemesis->state = WAITING_JUMPTACK;
        }
    }
    if (nemesis->direction == LEFT) {
        goal.x = 2350;
        goal.y = 3300;
        if (jump_trajectory(nemesis, goal) == 0) {
            nemesis->state = WAITING_JUMPTACK;
        }
    }
    if (nemesis->direction == RIGHT) {
        goal.x = 350;
        goal.y = 3300;
        if (jump_trajectory(nemesis, goal) == 0) {
            nemesis->state = WAITING_JUMPTACK;
        }
    }
    sfSprite_setPosition(nemesis->sprite, nemesis->coord);
    return nemesis;
}

boss_t *jump_nemesis_animation(boss_t *nemesis)
{
    nemesis->chrono_jump = get_chrono(nemesis->chrono_jump);
    if (nemesis->state == JUMPING
    && nemesis->chrono_jump.seconds > 0.000001) {
        launch_jump(nemesis);
        sfClock_restart(nemesis->chrono_jump.clock);
    }
    return nemesis;
}

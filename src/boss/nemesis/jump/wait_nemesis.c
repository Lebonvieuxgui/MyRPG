/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** wait_nemesis
*/
#include "myrpg.h"

static boss_t *choose_direction_jump(boss_t *nemesis)
{
    if (nemesis->direction == DOWN) {
        nemesis->rect.top = 5760;
    }
    if (nemesis->direction == UP) {
        nemesis->rect.top = 6048;
    }
    if (nemesis->direction == LEFT) {
        nemesis->rect.top = 6336;
    }
    if (nemesis->direction == RIGHT) {
        nemesis->rect.top = 6624;
    }
    return nemesis;
}

boss_t *wait_jumptack_nemesis(boss_t *nemesis)
{
    static int start = 0;

    if(nemesis->state == WAITING_JUMPTACK) {
        if (start == 0) {
            nemesis->rect.top = 0;
            nemesis->rect.left = 0;
            sfClock_restart(nemesis->Chrono_wait.clock);
            start = 1;
        }
        nemesis->Chrono_wait = get_chrono(nemesis->Chrono_wait);
        if (nemesis->Chrono_wait.seconds > 0.4) {
            nemesis->state = JUMPTACK;
            choose_direction_jump(nemesis);
            sfClock_restart(nemesis->Chrono_wait.clock);
            start = 0;
        }
    }
    return nemesis;
}

boss_t *wait_jumpjo_nemesis(boss_t *nemesis)
{
    static int start = 0;

    if (nemesis->state == WAITING_JUMPJO) {
        if (start == 0) {
            nemesis->rect.top = 0;
            nemesis->rect.left = 0;
            sfClock_restart(nemesis->Chrono_wait.clock);
            start = 1;
        }
        nemesis->Chrono_wait = get_chrono(nemesis->Chrono_wait);
        if (nemesis->Chrono_wait.seconds > 0.4) {
            jumpjo_nemesis(nemesis);
            sfClock_restart(nemesis->Chrono_wait.clock);
            start = 0;
        }
    }
    return nemesis;
}

boss_t *wait_jump_nemesis(boss_t *nemesis)
{
    static int start = 0;

    if(nemesis->state == WAITING) {
        if (start == 0) {
            nemesis->rect.top = 0;
            nemesis->rect.left = 0;
            sfClock_restart(nemesis->Chrono_wait.clock);
            start = 1;
        }
        nemesis->Chrono_wait = get_chrono(nemesis->Chrono_wait);
        if (nemesis->Chrono_wait.seconds > 0.4) {
            jump_nemesis(nemesis);
            sfClock_restart(nemesis->Chrono_wait.clock);
            start = 0;
        }
    }
    return nemesis;
}

boss_t *wait_nemesis(boss_t *nemesis, float wait_time)
{
    static int start = 0;

    if (start == 0) {
        sfClock_restart(nemesis->Chrono_wait.clock);
        start = 1;
    }
    if (nemesis->Chrono_wait.seconds > wait_time) {
        return_idle_nemesis(nemesis);
        sfClock_restart(nemesis->Chrono_wait.clock);
        start = 0;
    }
    return nemesis;
}

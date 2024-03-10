/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** nemesis_animation
*/
#include "myrpg.h"

static boss_t *change_frame(boss_t *nemesis)
{
    nemesis->rect.left = nemesis->rect.left + 288;
    if (nemesis->state == IDLE || nemesis->state == WAITING
    || nemesis->state == WAITING_JUMPTACK
    || nemesis->state == WAITING_JUMPJO) {
        if (nemesis->rect.left > 1350)
            nemesis->rect.left = 0;
    } else if (nemesis->state == MOVING) {
        if (nemesis->rect.left > 1728)
            nemesis->rect.left = 0;
    } else if (nemesis->state == ATTACKING) {
        if (nemesis->rect.left > 1720) {
            nemesis->rect.left = 0;
            return_idle_nemesis(nemesis);
        }
    } else if (nemesis->state == JUMPING
    || nemesis->state == JUMPTACK || nemesis->state == JUMP_JUMPJO) {
        if (nemesis->rect.left > 860)
            nemesis->rect.left = 576;
    } else if (nemesis->state == ZONETACK) {
        if (nemesis->rect.left > 1720) {
            nemesis->rect.left = 0;
            return_idle_nemesis(nemesis);
        }
    } else if (nemesis->state == PROJO) {
        if (nemesis->rect.left > 860) {
            nemesis->rect.left = 576;
            projo_nemesis(nemesis);
            return_idle_nemesis(nemesis);
        }
    } else if (nemesis->state == DEAD) {
        if (nemesis->rect.left > 1430)
            nemesis->rect.left = 1152;
    }
    return nemesis;
}

boss_t *return_idle_nemesis(boss_t *nemesis)
{
    nemesis->state = IDLE;
    if (nemesis->direction == DOWN)
        nemesis->rect.top = 0;
    if (nemesis->direction == UP)
        nemesis->rect.top = 288;
    if (nemesis->direction == LEFT)
        nemesis->rect.top = 576;
    if (nemesis->direction == RIGHT)
        nemesis->rect.top = 864;
    return nemesis;
}

boss_t *animation_nemesis(boss_t *nemesis)
{
    float timer = 0.15;

    if (nemesis->state == DEAD)
        timer = 0.3;
    if (nemesis->state == ZONETACK)
        timer = 0.21;
    nemesis->chrono_anim = \
    get_chrono(nemesis->chrono_anim);
    if (nemesis->chrono_anim.seconds > timer) {
        change_frame(nemesis);
        sfSprite_setTextureRect(nemesis->sprite, nemesis->rect);
        sfClock_restart(nemesis->chrono_anim.clock);
    }
    timer = 0.2;
    return nemesis;
}

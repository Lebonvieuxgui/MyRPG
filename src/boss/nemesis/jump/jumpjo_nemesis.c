/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** jump_to_projo
*/
#include "myrpg.h"

static sfVector2f find_goal(player_t *player)
{
    sfVector2f goal;
    static int i = 0;

    if (i == 0) {
        if (player->coord.x < 1200 && player->coord.x > 1600)
            goal.x = 1400;
        else
            goal.x = 1800;
        goal.y = player->coord.y;
        i = 1;
    } else {
        if (player->coord.y < 3000 && player->coord.y > 3400)
            goal.y = 3200;
        else
            goal.y = 3600;
        goal.x = player->coord.x;
        i = 0;
    }
    return goal;
}

static boss_t *launch_jump(boss_t *nemesis, player_t *player)
{
    static sfVector2f goal;
    static int i = 0;

    if (i == 0) {
        goal = find_goal(player);
        i = 1;
    }
    if (jump_trajectory(nemesis, goal) == 0) {
        nemesis->rect.top = 5760;
        nemesis->rect.left = 0;
        nemesis->state = PROJO;
        i = 0;
    }
    sfSprite_setPosition(nemesis->sprite, nemesis->coord);
    return nemesis;
}

boss_t *jumpjo_nemesis_animation(boss_t *nemesis, player_t *player)
{
    nemesis->chrono_jump = get_chrono(nemesis->chrono_jump);
    if (nemesis->state == JUMP_JUMPJO
    && nemesis->chrono_jump.seconds > 0.000001) {
        launch_jump(nemesis, player);
        sfClock_restart(nemesis->chrono_jump.clock);
    }
    return nemesis;
}

void launch_jumpjo(boss_t *nemesis)
{
    death_nemesis(nemesis);
    if (nemesis->dead == sfFalse) {
        if (nemesis->life < 4) {
            nemesis->state = WAITING_JUMPJO;
            wait_jumpjo_nemesis(nemesis);
        } else
            nemesis->state = HURT;
    }
}

boss_t *jumpjo_nemesis(boss_t *nemesis)
{
    nemesis->state = JUMP_JUMPJO;
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
    nemesis->rect.left = 0;
    return nemesis;
}


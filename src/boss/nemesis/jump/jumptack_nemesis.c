/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** jumptack_nemesis
*/
#include "myrpg.h"

static boss_t *launch_jumptack(boss_t *nemesis, player_t *player)
{
    if (jump_trajectory(nemesis, player->coord) == 0) {
        if (zonetack_nemesis(nemesis, player) == 0) {
            nemesis->rect.left = 576;
            nemesis->state = ZONETACK;
            touched_player_nemesis(nemesis, player);
        } else
            return_idle_nemesis(nemesis);
    }
    sfSprite_setPosition(nemesis->sprite, nemesis->coord);
    return nemesis;
}

boss_t *jumptack_nemesis_animation(boss_t *nemesis, player_t *player)
{
    nemesis->chrono_jump = get_chrono(nemesis->chrono_jump);
    if (nemesis->state == JUMPTACK
    && nemesis->chrono_jump.seconds > 0.000001) {
        launch_jumptack(nemesis, player);
        sfClock_restart(nemesis->chrono_jump.clock);
    }
    return nemesis;
}

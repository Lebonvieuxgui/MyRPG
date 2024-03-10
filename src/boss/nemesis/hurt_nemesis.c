/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** hurt_nemesis
*/
#include "myrpg.h"

boss_t *reduce_life_nemesis(boss_t *nemesis)
{
    if ((nemesis->state == HURT || nemesis->state == WAITING_JUMPJO)
    && nemesis->touched == 0) {
        nemesis->life = nemesis->life - 1;
        nemesis->touched = sfTrue;
    }
    if (nemesis->state == IDLE)
        nemesis->touched = sfFalse;
    return nemesis;
}

boss_t *touched_nemesis(boss_t *nemesis, player_t *player)
{
    if (player->direction == UP)
        nemesis->rect.top = 3744;
    if (player->direction == DOWN)
        nemesis->rect.top = 3456;
    if (player->direction == LEFT)
        nemesis->rect.top = 4320;
    if (player->direction == RIGHT)
        nemesis->rect.top = 4032;
    nemesis->rect.left = 0;
    nemesis->state = HURT;
    sfSprite_setTextureRect(nemesis->sprite, nemesis->rect);
    return nemesis;
}

static boss_t *move_knockback(boss_t *nemesis, player_t *player)
{
    if (player->direction == DOWN)
        nemesis->coord.y = nemesis->coord.y + 3;
    if (player->direction == UP)
        nemesis->coord.y = nemesis->coord.y - 3;
    if (player->direction == LEFT)
        nemesis->coord.x = nemesis->coord.x - 3;
    if (player->direction == RIGHT)
        nemesis->coord.x = nemesis->coord.x + 3;
    if (nemesis->rect.left > 860) {
        nemesis->rect.left = 0;
        return_idle_nemesis(nemesis);
    }
    return nemesis;
}

boss_t *knockback_nemesis(boss_t *nemesis, player_t *player)
{
    nemesis->chrono_knockback = get_chrono(nemesis->chrono_knockback);
    if ((nemesis->state == HURT)
    && nemesis->chrono_knockback.seconds > 0.000001) {
        move_knockback(nemesis, player);
        sfClock_restart(nemesis->chrono_knockback.clock);
    }
    sfSprite_setPosition(player->sprite, player->coord);
    return nemesis;
}

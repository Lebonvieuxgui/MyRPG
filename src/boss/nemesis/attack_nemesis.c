/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** attack_nemesis
*/
#include "myrpg.h"

boss_t *jump_nemesis(boss_t *nemesis)
{
    nemesis->state = JUMPING;
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

static void launch_jumptack(boss_t *nemesis)
{
    if (nemesis->life < 8) {
        nemesis->state = WAITING;
        wait_jump_nemesis(nemesis);
    }
}

player_t *detect_attack_nemesis(boss_t *nemesis, player_t *player)
{
    attack_nemesis(nemesis, player);
    if (nemesis->state == ATTACKING && nemesis->rect.left == 576
    && player->state != DASHING && nemesis->state != WAITING
    && nemesis->state != WAITING_JUMPTACK) {
        if (attack_range_nemesis(player, nemesis) == 0) {
            touched_player_nemesis(nemesis, player);
            launch_jumptack(nemesis);
        }
    }
    return player;
}

boss_t *attack_nemesis(boss_t *nemesis, player_t *player)
{
    if (in_range_nemesis(nemesis, player) == 0
    && (nemesis->state == IDLE || nemesis->state == MOVING)
    && player->dead == sfFalse) {
        nemesis->state = ATTACKING;
        nemesis->rect.left = 0;
        if (nemesis->direction == DOWN)
            nemesis->rect.top = 2304;
        if (nemesis->direction == UP)
            nemesis->rect.top = 2592;
        if (nemesis->direction == LEFT)
            nemesis->rect.top = 2880;
        if (nemesis->direction == RIGHT)
            nemesis->rect.top = 3168;
        sfSprite_setTextureRect(nemesis->sprite, nemesis->rect);
    }
    return nemesis;
}
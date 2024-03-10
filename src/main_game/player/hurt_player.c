/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** hurt_player
*/
#include "myrpg.h"

player_t *reduce_life_player(player_t *player)
{
    static int touched = 0;

    if ((player->state == HURT || player->state == HURT_NEMESIS) && touched == 0) {
        player->life = player->life - 1;
        touched = 1;
    }
    if (player->state != HURT && player->state != HURT_NEMESIS)
        touched = 0;
    return player;
}

player_t *touched_player_nemesis(boss_t *nemesis, player_t *player)
{
    if (player->state != DASHING && player->dead == sfFalse
    && is_blocked_nemesis(player, nemesis) == 0) {
        if (nemesis->direction == UP) {
            player->rect.top = 2304;
            player->pushback = UP;
        }
        if (nemesis->direction == DOWN) {
            player->rect.top = 2496;
            player->pushback = DOWN;
        }
        if (nemesis->direction == RIGHT) {
            player->rect.top = 2688;
            player->pushback = RIGHT;
        }
        if (nemesis->direction == LEFT) {
            player->rect.top = 2880;
            player->pushback = LEFT;
        }
        player->rect.left = 0;
        player->state = HURT_NEMESIS;
        sfSprite_setTextureRect(player->sprite, player->rect);
    }
    return player;
}

player_t *touched_player(enemy_t *enemy, player_t *player)
{
    if (player->state != DASHING && player->dead == sfFalse
    && is_blocked(player, enemy) == 0) {
        if (enemy->direction == UP) {
            player->rect.top = 2304;
            player->pushback = UP;
        }
        if (enemy->direction == DOWN) {
            player->rect.top = 2496;
            player->pushback = DOWN;
        }
        if (enemy->direction == RIGHT) {
            player->rect.top = 2688;
            player->pushback = RIGHT;
        }
        if (enemy->direction == LEFT) {
            player->rect.top = 2880;
            player->pushback = LEFT;
        }
        player->rect.left = 0;
        player->state = HURT;
        sfSprite_setTextureRect(player->sprite, player->rect);
    }
    return player;
}

static player_t *move_knockback(game_object_t *game, player_t *player)
{
    int knockback = 4;

    if (player->state == HURT_NEMESIS)
        knockback = 8;
    if (player->pushback == DOWN && collision_down(game, 50, -20) == 0)
        player->coord.y = player->coord.y + knockback;
    if (player->pushback == UP && collision_up(game, 50, -200) == 0)
        player->coord.y = player->coord.y - knockback;
    if (player->pushback == LEFT && collision_left(game, 0 , -43) == 0)
        player->coord.x = player->coord.x - knockback;
    if (player->pushback == RIGHT && collision_right(game, 150, -43) == 0)
        player->coord.x = player->coord.x + knockback;
    sfSprite_setPosition(player->sprite, player->coord);
    death_player(player);
    if (player->rect.left > 570) {
        player->rect.left = 0;
        return_idle(player);
    }
    return player;
}

player_t *knockback_player(game_object_t *game, player_t *player)
{
    player->chrono_knockback = get_chrono(player->chrono_knockback);
    if (((player->state == HURT || player->state == HURT_NEMESIS))
    && player->dead == sfFalse
    && player->chrono_knockback.seconds > 0.000001) {
        move_knockback(game, player);
        sfClock_restart(player->chrono_knockback.clock);
    }
    sfSprite_setPosition(player->sprite, player->coord);
    return player;
}

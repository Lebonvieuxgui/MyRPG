/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** block_player
*/
#include "myrpg.h"

player_t *block_animation(player_t *player)
{
    if (player->rect.left > 760)
        player->rect.left = 576;
    return player;
}

static player_t *block_direction(player_t *player)
{
    if (player->direction == DOWN) {
        player->rect.top = 1536;
    }
    if (player->direction == UP) {
        player->rect.top = 1728;
    }
    if (player->direction == LEFT) {
        player->rect.top = 1920;
    }
    if (player->direction == RIGHT) {
        player->rect.top = 2112;
    }
    return player;
}

static player_t *set_pushback(player_t *player, enemy_t *enemy)
{
    if (enemy->direction == UP) {
        player->pushback = UP;
    }
    if (enemy->direction == DOWN) {
        player->pushback = DOWN;
    }
    if (enemy->direction == RIGHT) {
        player->pushback = RIGHT;
    }
    if (enemy->direction == LEFT) {
        player->pushback = LEFT;
    }
    return player;
}

int is_blocked(player_t *player, enemy_t *enemy)
{
    if (player->state == IDLE || player->state == MOVING) {
        return 0;
    } else if ((player->direction == DOWN && enemy->direction != UP)
    || (player->direction == UP && enemy->direction != DOWN)
    || (player->direction == LEFT && enemy->direction != RIGHT)
    || (player->direction == RIGHT && enemy->direction != LEFT)) {
        return 0;
    }
    set_pushback(player, enemy);
    player->state = BLOCKED;
    return 1;
}

player_t *block_player(player_t *player)
{
    if (player->block == sfTrue && (player->state == IDLE
    || player->state == MOVING || player->state == BLOCKING)) {
        if (sfKeyboard_isKeyPressed(sfKeyC)) {
            player->state = BLOCKING;
            player->rect.left = 576;
            block_direction(player);
        }
        if (player->state == BLOCKING && !sfKeyboard_isKeyPressed(sfKeyC))
            return_idle(player);
    }
    return player;
}

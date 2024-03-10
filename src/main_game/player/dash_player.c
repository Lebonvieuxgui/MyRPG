/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** dash_player
*/
#include "myrpg.h"

static player_t *data_player(game_object_t *game, player_t *player)
{
    if (player->rect.left > 380 && player->rect.left < 570) {
        if (player->direction == DOWN && collision_down(game, 50, 50) == 0)
            player->coord.y = player->coord.y + 20;
        if (player->direction == UP && collision_up(game, 50, -100) == 0)
            player->coord.y = player->coord.y - 20;
        if (player->direction == LEFT && collision_left(game, -40, -43) == 0)
            player->coord.x = player->coord.x - 20;
        if (player->direction == RIGHT && collision_right(game, 75, -43) == 0)
            player->coord.x = player->coord.x + 20;
    } else {
        if (player->direction == DOWN)
            player->coord.y = player->coord.y + 3;
        if (player->direction == UP)
            player->coord.y = player->coord.y - 3;
        if (player->direction == LEFT)
            player->coord.x = player->coord.x - 3;
        if (player->direction == RIGHT)
            player->coord.x = player->coord.x + 3;
    }
    return player;
}

player_t *dash_animation(game_object_t *game, player_t *player)
{
    player->chrono_dash = get_chrono(player->chrono_dash);
    if (player->state == DASHING && player->dash == sfTrue
    && player->chrono_dash.seconds > 0.000001) {
        if (player->rect.left > 760) {
            player->rect.left = 0;
            sfClock_restart(player->chrono_skill.clock);
            return_idle(player);
        }
        data_player(game, player);
        sfClock_restart(player->chrono_dash.clock);
    }
    sfSprite_setPosition(player->sprite, player->coord);
    return player;
}

static player_t *dash_direction(player_t *player)
{
    if (player->direction == DOWN) {
        player->rect.top = 3840;
    }
    if (player->direction == UP) {
        player->rect.top = 4032;
    }
    if (player->direction == LEFT) {
        player->rect.top = 4224;
    }
    if (player->direction == RIGHT) {
        player->rect.top = 4416;
    }
    return player;
}

player_t *dash_player(player_t *player)
{
    player->chrono_skill = get_chrono(player->chrono_skill);
    if (player->dash == sfTrue && player->chrono_skill.seconds > 1.5) {
        if (sfKeyboard_isKeyPressed(sfKeyD)) {
            player->state = DASHING;
            player->rect.left = 0;
            dash_direction(player);
        }
    }
    return player;
}

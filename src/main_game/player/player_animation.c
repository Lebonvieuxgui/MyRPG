/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** player_animation
*/
#include "myrpg.h"

static player_t *change_frame(player_t *player)
{
    player->rect.left = player->rect.left + 192;
    if (player->state == IDLE) {
        if (player->rect.left > 900)
            player->rect.left = 0;
    } else if (player->state == MOVING) {
        if (player->rect.left > 1530)
            player->rect.left = 0;
    } else if (player->state == ATTACKING) {
        if (player->rect.left > 1150) {
            player->rect.left = 0;
            return_idle(player);
        }
    } else if (player->state == BLOCKING || player->state == BLOCKED
    || player->state == BLOCKED_NEMESIS)
        if (player->rect.left > 760)
            player->rect.left = 576;
    return player;
}

static player_t *change_frame_death(player_t *player, game_object_t *game)
{
    player->rect.left = player->rect.left + 192;
    if (player->rect.left > 950) {
        player->rect.left = 576;
        game->GAMESTATE = GAMEOVER;
        game->GAMEOVER = DO_NOT_EXIST_GO;
        sfRenderWindow_setMouseCursorVisible(game->window->w, sfTrue);
    }
    return player;
}

Chrono_t get_chrono(Chrono_t chrono)
{
    chrono.time = sfClock_getElapsedTime(chrono.clock);
    chrono.seconds = chrono.time.microseconds / 1000000.0;
    return chrono;
}

player_t *player_animation(player_t *player, game_object_t *game)
{
    float timer = 0.15;

    if (player->state == DEAD || player->dead == sfTrue)
        timer = 0.3;
    player->chrono_anim = get_chrono(player->chrono_anim);
    if (player->chrono_anim.seconds > timer) {
        if (player->dead == sfFalse)
            change_frame(player);
        else
            change_frame_death(player, game);
        sfSprite_setTextureRect(player->sprite, player->rect);
        sfClock_restart(player->chrono_anim.clock);
    }
    return player;
}

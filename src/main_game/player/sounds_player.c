/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** sounds_player
*/
#include "myrpg.h"

player_t *sounds_player(player_t *player)
{
    player->chrono_sounds = get_chrono(player->chrono_sounds);
    if (player->chrono_sounds.seconds > 0.2) {

        if (player->rect.top > 1530 && player->rect.top < 2300
        && ((player->rect.left > 0 && player->rect.left < 380))) {
            sfSound_play(player->sounds[1]);
            sfClock_restart(player->chrono_sounds.clock);
        }
        if (player->rect.top > 760 && player->rect.top < 1530
        && ((player->rect.left > 760 && player->rect.left < 960)
        || (player->rect.left >= 0 && player->rect.left < 190))) {
            sfSound_play(player->sounds[0]);
            sfClock_restart(player->chrono_sounds.clock);
        }
    }
    return player;
}

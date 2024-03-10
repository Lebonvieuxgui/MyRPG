/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** sounds_nemesis
*/
#include "myrpg.h"

boss_t *sounds_nemesis(boss_t *nemesis)
{
    nemesis->chrono_sounds = get_chrono(nemesis->chrono_sounds);
    if (nemesis->chrono_sounds.seconds > 0.5) {
        if (nemesis->rect.top > 1150 && nemesis->rect.top < 2304
        && ((nemesis->rect.left > 1150 && nemesis->rect.left < 1440)
        || (nemesis->rect.left >= 0 && nemesis->rect.left < 280))) {
            sfSound_play(nemesis->sounds[0]);
            sfClock_restart(nemesis->chrono_sounds.clock);
        }
        if (nemesis->rect.top > 2300 && nemesis->rect.top < 3450
        && ((nemesis->rect.left > 280 && nemesis->rect.left < 570))) {
            sfSound_play(nemesis->sounds[1]);
            sfClock_restart(nemesis->chrono_sounds.clock);
        }
    }
    return nemesis;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** launch_rocks
*/
#include "myrpg.h"

static enemy_t *horizontal_launch(enemy_t *slinger)
{
    if (slinger->direction == LEFT) {
        slinger->list_rocks[slinger->rock]->coord.x = slinger->coord.x - 20;
        slinger->list_rocks[slinger->rock]->coord.y = slinger->coord.y + 80;
        slinger->list_rocks[slinger->rock]->launched = sfTrue;
        slinger->list_rocks[slinger->rock]->direction = LEFT;
        sfSprite_setPosition(slinger->list_rocks[slinger->rock]->sprite,
        slinger->list_rocks[slinger->rock]->coord);
    }
    if (slinger->direction == RIGHT) {
        slinger->list_rocks[slinger->rock]->coord.x = slinger->coord.x + 160;
        slinger->list_rocks[slinger->rock]->coord.y = slinger->coord.y + 80;
        slinger->list_rocks[slinger->rock]->launched = sfTrue;
        slinger->list_rocks[slinger->rock]->direction = RIGHT;
        sfSprite_setPosition(slinger->list_rocks[slinger->rock]->sprite,
        slinger->list_rocks[slinger->rock]->coord);
    }
    return slinger;
}

static enemy_t *vertical_launch(enemy_t *slinger)
{
    if (slinger->direction == DOWN) {
        slinger->list_rocks[slinger->rock]->coord.x = slinger->coord.x + 80;
        slinger->list_rocks[slinger->rock]->coord.y = slinger->coord.y + 150;
        slinger->list_rocks[slinger->rock]->launched = sfTrue;
        slinger->list_rocks[slinger->rock]->direction = DOWN;
        sfSprite_setPosition(slinger->list_rocks[slinger->rock]->sprite,
        slinger->list_rocks[slinger->rock]->coord);
    }
    if (slinger->direction == UP) {
        slinger->list_rocks[slinger->rock]->coord.x = slinger->coord.x + 80;
        slinger->list_rocks[slinger->rock]->coord.y = slinger->coord.y - 30;
        slinger->list_rocks[slinger->rock]->launched = sfTrue;
        slinger->list_rocks[slinger->rock]->direction = UP;
        sfSprite_setPosition(slinger->list_rocks[slinger->rock]->sprite,
        slinger->list_rocks[slinger->rock]->coord);
    }
    return slinger;
}

enemy_t *launch_rock(enemy_t *slinger)
{
    slinger->list_rocks[slinger->rock]->chrono_launch =
    get_chrono(slinger->list_rocks[slinger->rock]->chrono_launch);
    if (slinger->list_rocks[slinger->rock]->chrono_launch.seconds > 0.8) {
        if (slinger->rect.left > 490 && slinger->rect.left > 680) {
            vertical_launch(slinger);
            horizontal_launch(slinger);
            slinger->rock = slinger->rock + 1;
        }
        if (slinger->rock > 9)
            slinger->rock = 0;
        sfClock_restart(slinger->list_rocks[slinger->rock]->
        chrono_launch.clock);
    }
    return slinger;
}

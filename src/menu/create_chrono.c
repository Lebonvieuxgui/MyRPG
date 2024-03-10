/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** create_crono
*/

#include "myrpg.h"

game_clock_t *create_chrono(void)
{
    game_clock_t *test = malloc(sizeof(game_clock_t));

    if (!test)
        return NULL;
    test->clock = sfClock_create();
    test->time = sfTime_Zero;
    test->seconds = 0;
    return (test);
}

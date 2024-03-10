/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** place_room1
*/
#include "myrpg.h"

enemy_t **place_room1(enemy_t **list_enemies)
{
    list_enemies[0] = create_possesed(950, 600);
    list_enemies[1] = create_possesed(1200, 900);
    list_enemies[2] = create_possesed(1200, 500);
    list_enemies[3] = create_possesed(2350, 1350);
    list_enemies[4] = create_possesed(2550, 1100);
    list_enemies[5] = create_possesed(1200, 1400);
    list_enemies[6] = create_possesed(1600, 1450);
    list_enemies[7] = create_possesed(300, 1000);
    list_enemies[8] = create_possesed(1950, 750);
    list_enemies[9] = create_possesed(3000, 750);
    list_enemies[10] = create_possesed(2000, 450);
    list_enemies[11] = create_possesed(2800, 350);
    return list_enemies;
}

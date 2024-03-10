/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** place_room2
*/
#include "myrpg.h"

static enemy_t **place_room2_5(enemy_t **list_enemies)
{
    list_enemies[32] = create_slinger(5500, 400);
    list_enemies[33] = create_slinger(5500, 500);
    list_enemies[34] = create_possesed(6400, 600);
    list_enemies[35] = create_possesed(6200, 650);
    return list_enemies;
}

static enemy_t **place_room2_bis(enemy_t **list_enemies)
{
    list_enemies[30] = create_possesed(7000, 900);
    list_enemies[31] = create_possesed(7400, 900);
    place_room2_5(list_enemies);
    return list_enemies;
}

enemy_t **place_room2(enemy_t **list_enemies)
{
    list_enemies[12] = create_possesed(3700, 300);
    list_enemies[13] = create_possesed(2000, 250);
    list_enemies[14] = create_possesed(4700, 650);
    list_enemies[15] = create_possesed(4600, 600);
    list_enemies[16] = create_possesed(4500, 700);
    list_enemies[17] = create_possesed(3600, 600);
    list_enemies[18] = create_possesed(3750, 650);
    list_enemies[19] = create_slinger(4800, 2000);
    list_enemies[20] = create_slinger(5600, 2200);
    list_enemies[21] = create_possesed(5400, 2100);
    list_enemies[22] = create_possesed(6500, 2000);
    list_enemies[23] = create_possesed(6400, 1700);
    list_enemies[24] = create_slinger(6900, 1400);
    list_enemies[25] = create_possesed(6800, 1500);
    list_enemies[26] = create_possesed(6100, 1000);
    list_enemies[27] = create_possesed(6050, 1300);
    list_enemies[28] = create_possesed(6600, 1300);
    list_enemies[29] = create_possesed(6200, 1200);
    place_room2_bis(list_enemies);
    return list_enemies;
}
/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** place_room4
*/
#include "myrpg.h"

enemy_t **place_room4(enemy_t **list_enemies)
{
    list_enemies[47] = create_possesed(3000, 2300);
    list_enemies[48] = create_possesed(3600, 2400);
    list_enemies[49] = create_possesed(3700, 4100);
    list_enemies[50] = create_possesed(3450, 2900);
    list_enemies[51] = create_possesed(3250, 2900);
    list_enemies[52] = create_possesed(2900, 4120);
    return list_enemies;
}

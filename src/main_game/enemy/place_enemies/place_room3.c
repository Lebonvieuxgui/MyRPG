/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** place_room3
*/
#include "myrpg.h"

enemy_t **place_room3(enemy_t **list_enemies)
{
    list_enemies[36] = create_possesed(6400, 2700);
    list_enemies[37] = create_slinger(7300, 3000);
    list_enemies[38] = create_possesed(7000, 3850);
    list_enemies[39] = create_possesed(7100, 3850);
    list_enemies[40] = create_possesed(7200, 3850);
    list_enemies[41] = create_possesed(7300, 3850);
    list_enemies[42] = create_possesed(7400, 3850);
    list_enemies[43] = create_possesed(7500, 3850);
    list_enemies[44] = create_possesed(5400, 3400);
    list_enemies[45] = create_possesed(4100, 2400);
    list_enemies[46] = create_possesed(4900, 2600);
    return list_enemies;
}

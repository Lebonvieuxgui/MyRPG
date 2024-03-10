/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** create_map
*/
#include "myrpg.h"

sfSprite *create_map(void)
{
    sfTexture *map_text = sfTexture_createFromFile("Rsrce/map.png", NULL);
    sfSprite *map = sfSprite_create();
    sfVector2f position;

    position.x = 0;
    position.y = 200;
    sfSprite_setTexture(map, map_text, sfFalse);
    sfSprite_setPosition(map, position);
    return (map);
}

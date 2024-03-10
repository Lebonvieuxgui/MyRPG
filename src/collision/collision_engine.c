/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** collision_engine
*/
#include "myrpg.h"

sfFloatRect get_rect(game_object_t *game)
{
    sfFloatRect rect;

    rect = sfSprite_getGlobalBounds(game->player->sprite);
    return rect;
}

static int collisions_doors(game_object_t *game, int x, int y)
{
    if (game->objects[1]->taked == sfFalse
    && ((x > 2300 && x < 2600) && (y > 780 && y < 800)))
        return 1;
    if (game->objects[2]->taked == sfFalse
    && ((x > 7100 && x < 7400) && (y > 650 && y < 700)))
        return 1;
    if (game->objects[3]->taked == sfFalse
    && ((x > 5800 && x < 6000) && (y > 2250 && y < 2300)))
        return 1;
    if (game->objects[4]->taked == sfFalse
    && ((x > 3000 && x < 3200) && (y > 2050 && y < 2100)))
        return 1;
    return 0;
}

int check_black_or_white(game_object_t *game, int x, int y)
{
    sfColor pixel;

    if (collisions_doors(game, x, y) == 1)
        return 1;
    if (game->GAMESTATE == BOSS
    && ((x > 2880 && x < 2950) && (y > 3000 && y < 3600)))
        return 1;
    pixel = sfImage_getPixel(game->hitbox, x, y);
    if (pixel.r == 0 && pixel.g == 0 && pixel.b == 0)
        return 1;
    else
        return 0;
}

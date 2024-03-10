/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** display_doors
*/

#include "myrpg.h"

static void display_doorframes_bis(game_object_t *game, sfVector2f scale)
{
    sfSprite_setScale(game->doorframes[2]->sprite, scale);
    sfSprite_setPosition(game->doorframes[2]->sprite,(sfVector2f){5860, 2379});
    sfRenderWindow_drawSprite(game->window->w,
    game->doorframes[2]->sprite, NULL);
    sfSprite_setScale(game->doorframes[3]->sprite, scale);
    sfSprite_setPosition(game->doorframes[3]->sprite,(sfVector2f){3110, 2150});
    sfRenderWindow_drawSprite(game->window->w,
    game->doorframes[3]->sprite, NULL);
}

static void display_doorframes(game_object_t *game)
{
    sfVector2f scale;

    scale.x = 0.5;
    scale.y = 0.5;
    sfSprite_setScale(game->doorframes[0]->sprite, scale);
    sfSprite_setPosition(game->doorframes[0]->sprite,(sfVector2f){2390, 900});
    sfRenderWindow_drawSprite(game->window->w,
    game->doorframes[0]->sprite, NULL);
    sfSprite_setScale(game->doorframes[1]->sprite, scale);
    sfSprite_setPosition(game->doorframes[1]->sprite,(sfVector2f){7180, 760});
    sfRenderWindow_drawSprite(game->window->w,
    game->doorframes[1]->sprite, NULL);
    display_doorframes_bis(game, scale);
}

void display_doors(game_object_t *game)
{
    if (game->objects[1]->taked == sfFalse)
        sfRenderWindow_drawSprite(game->window->w,
        game->doors[0]->sprite, NULL);
    if (game->objects[2]->taked == sfFalse)
        sfRenderWindow_drawSprite(game->window->w,
        game->doors[1]->sprite, NULL);
    if (game->objects[3]->taked == sfFalse)
        sfRenderWindow_drawSprite(game->window->w,
        game->doors[2]->sprite, NULL);
    if (game->objects[4]->taked == sfFalse)
        sfRenderWindow_drawSprite(game->window->w,
        game->doors[3]->sprite, NULL);
    display_doorframes(game);
}

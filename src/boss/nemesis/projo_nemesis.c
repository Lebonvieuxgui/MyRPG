/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** projo_nemesis
*/
#include "myrpg.h"

void display_projos(game_object_t *game, projectile_t **list_projos)
{
    if (list_projos[0]->launched == sfTrue) {
        sfRenderWindow_drawSprite(game->window->w,
        list_projos[0]->sprite, NULL);
    }
    if (list_projos[1]->launched == sfTrue) {
        sfRenderWindow_drawSprite(game->window->w,
        list_projos[1]->sprite, NULL);
    }
    if (list_projos[2]->launched == sfTrue) {
        sfRenderWindow_drawSprite(game->window->w,
        list_projos[2]->sprite, NULL);
    }
    if (list_projos[3]->launched == sfTrue) {
        sfRenderWindow_drawSprite(game->window->w,
        list_projos[3]->sprite, NULL);
    }
}

boss_t *projo_nemesis(boss_t *nemesis)
{
    if (nemesis->state == PROJO) {
        nemesis->list_projos[0]->launched = sfTrue;
        nemesis->list_projos[0]->coord.x = nemesis->coord.x + 72;
        nemesis->list_projos[0]->coord.y = nemesis->coord.y + 140;
        sfSprite_setPosition(nemesis->list_projos[0]->sprite,
        nemesis->list_projos[0]->coord);
        nemesis->list_projos[1]->launched = sfTrue;
        nemesis->list_projos[1]->coord.x = nemesis->coord.x + 72;
        nemesis->list_projos[1]->coord.y = nemesis->coord.y;
        sfSprite_setPosition(nemesis->list_projos[1]->sprite,
        nemesis->list_projos[1]->coord);
        nemesis->list_projos[2]->launched = sfTrue;
        nemesis->list_projos[2]->coord.x = nemesis->coord.x;
        nemesis->list_projos[2]->coord.y = nemesis->coord.y + 72;
        sfSprite_setPosition(nemesis->list_projos[2]->sprite,
        nemesis->list_projos[2]->coord);
        nemesis->list_projos[3]->launched = sfTrue;
        nemesis->list_projos[3]->coord.x = nemesis->coord.x + 140;
        nemesis->list_projos[3]->coord.y = nemesis->coord.y + 72;
        sfSprite_setPosition(nemesis->list_projos[3]->sprite,
        nemesis->list_projos[3]->coord);
    }
    return nemesis;
}


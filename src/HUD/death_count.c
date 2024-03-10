/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** death_count
*/

#include "myrpg.h"

button_t **create_death_count(game_object_t *game)
{
    button_t **deathcount = malloc(sizeof(button_t) * 2);

    if (!deathcount)
        return NULL;
    deathcount[0] = malloc(sizeof(button_t));
    deathcount[0]->sprite = create_sprite("Rsrce/Deathcount :.png");
    deathcount[1] = malloc(sizeof(button_t));
    deathcount[1]->sprite = create_sprite("Rsrce/fontdeaths.png");
    deathcount[1]->rect.height = 80;
    deathcount[1]->rect.width = 100;
    deathcount[1]->rect.top = 0;
    deathcount[1]->rect.left = game->player->nb_deaths;
    return deathcount;
}

void death_count_engine(game_object_t *game, button_t **deathcount)
{
    sfVector2f position;
    sfVector2f size;

    size.x = 1.1;
    size.y = 1.1;
    position.x = game->coord_view.x - 960;
    position.y = game->coord_view.y + 265;
    sfSprite_setPosition(deathcount[0]->sprite, position);
    position.x += 150;
    sfSprite_setPosition(deathcount[1]->sprite, position);
    sfSprite_setScale(deathcount[0]->sprite, size);
    sfRenderWindow_drawSprite(game->window->w, deathcount[0]->sprite, NULL);
    sfSprite_setTextureRect(deathcount[1]->sprite, deathcount[1]->rect);
    sfRenderWindow_drawSprite(game->window->w, deathcount[1]->sprite, NULL);
}

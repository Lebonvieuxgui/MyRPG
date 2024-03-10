/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** heart_engine
*/

#include "myrpg.h"

static button_t *animation_heart(button_t *heart)
{
    start_chrono(heart->chrono);
    if (heart->chrono->seconds > 0.1) {
        heart->rect.left = move_rect_enemy(heart->rect, 39, 0, 230);
        sfSprite_setTextureRect(heart->sprite, heart->rect);
        sfClock_restart(heart->chrono->clock);
    }
    return heart;
}

void print_hearts(game_object_t *game, int i)
{
    if (!game || !game->heart[i])
        return;
    if (game->heart[i]->state == IS_CLICKED) {
        animation_heart(game->heart[i]);
        sfSprite_setPosition(game->heart[i]->sprite, game->heart[i]->pos);
        sfRenderWindow_drawSprite(game->window->w,
        game->heart[i]->sprite, NULL);
    }
}

button_t **taking_hearts(game_object_t *game, int i)
{
    if (!game || !game->heart[i])
        return NULL;
    if (game->player->coord.x > game->heart[i]->pos.x - 110
    && game->player->coord.x < game->heart[i]->pos.x + 10
    && game->player->coord.y > game->heart[i]->pos.y - 80
    && game->player->coord.y < game->heart[i]->pos.y + 40
    && game->player->life <= 6) {
            game->heart[i]->state = ISNT_CLICKED;
            game->heart[i]->pos.x += 7000;
            game->heart[i]->pos.y += 7000;
            sfSound_play(game->heart[i]->sounds[0]);
            game->player->life += 1;
    }
    return game->heart;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** game_over_engine
*/

#include "myrpg.h"

static void print_game_over_buttons(game_object_t *game, button_t **gameover)
{
    sfVector2f size;

    size.x = 1;
    size.y = 1;
    game->gameover[1]->pos.x = game->coord_view.x - 225;
    game->gameover[1]->pos.y = game->coord_view.y - 50;
    game->gameover[2]->pos.x = game->coord_view.x - 225;
    game->gameover[2]->pos.y = game->coord_view.y + 132;
    sfSprite_setScale(gameover[1]->sprite, size);
    sfSprite_setPosition(gameover[1]->sprite, game->gameover[1]->pos);
    sfRenderWindow_drawSprite(game->window->w, gameover[1]->sprite, NULL);
    sfSprite_setScale(gameover[2]->sprite, size);
    sfSprite_setPosition(gameover[2]->sprite, game->gameover[2]->pos);
    sfRenderWindow_drawSprite(game->window->w, gameover[2]->sprite, NULL);
}

static void print_game_over(game_object_t *game, button_t **gameover)
{
    sfVector2f position;

    position.x = game->coord_view.x - 960;
    position.y = game->coord_view.y - 540;
    sfSprite_setPosition(game->red, position);
    if (game->GAMEOVER == DO_NOT_EXIST_GO) {
        sfRenderWindow_drawSprite(game->window->w, game->red, NULL);
        game->GAMEOVER = EXIST_GO;
    }
    position.x += 650;
    position.y += 150;
    sfSprite_setPosition(gameover[0]->sprite, position);
    position.x -= 100;
    position.y += 200;
    sfSprite_setScale(gameover[3]->sprite, (sfVector2f){2, 3});
    sfSprite_setPosition(gameover[3]->sprite, position);
    sfRenderWindow_drawSprite(game->window->w, gameover[3]->sprite, NULL);
    print_game_over_buttons(game, gameover);
    check_hover_go(game, game->gameover);
    sfRenderWindow_drawSprite(game->window->w, gameover[0]->sprite, NULL);
}

game_object_t *game_over_engine(game_object_t *game)
{
    if (!game)
        return NULL;
    events_gameover(game, game->gameover);
    check_go_buttons(game, game->gameover);
    print_game_over(game, game->gameover);
    sfRenderWindow_display(game->window->w);
    return game;
}
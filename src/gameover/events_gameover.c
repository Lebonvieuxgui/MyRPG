/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** events_gameover
*/

#include "myrpg.h"

void check_go_buttons(game_object_t *game, button_t **gameover)
{
    if(gameover[1]->state == IS_CLICKED) {
        game->player->rect.top = 0;
        game->player->dead = sfFalse;
        game->player->state = IDLE;
        game->player->life = 6;
        if(game->player->nb_deaths <= 900) {
            game->player->nb_deaths += 100;
            game->deathcount[1]->rect.left = game->player->nb_deaths;
            gameover[1]->state = ISNT_CLICKED;
            game->GAMESTATE = GAME;
        }
        else if (game->player->nb_deaths > 900)
            game->GAMESTATE = END;
    }
    if(gameover[2]->state == IS_CLICKED){
        game->GAMESTATE = END;
    }
}

static void manage_click_go(button_t **gameover, sfEvent event)
{
    if (event.mouseButton.x >= 735 && event.mouseButton.y >= 455 &&
    event.mouseButton.x <= 1170 && event.mouseButton.y <= 560) {
        gameover[1]->state = IS_CLICKED;
    }
    if (event.mouseButton.x >= 735 && event.mouseButton.y >= 630 &&
    event.mouseButton.x <= 1170 && event.mouseButton.y <= 735) {
        gameover[2]->state = IS_CLICKED;
    }
}

void events_gameover(game_object_t *game, button_t **gameover)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(game->window->w, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyQ))
        game->GAMESTATE = END;
        if (event.type == sfEvtMouseButtonPressed &&
         event.mouseButton.button == sfMouseLeft) {
             manage_click_go(gameover, event);
         }
    }
}
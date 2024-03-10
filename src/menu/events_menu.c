/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** events_menu
*/

#include "myrpg.h"

static game_object_t *change_music_menu(game_object_t *game)
{
    if (!game)
        return NULL;
    sfMusic_destroy(game->gamesong);
    game->gamesong = sfMusic_createFromFile("Rsrce/catacombs.ogg");
    game->GAMESTATE = INTRO;
    sfMusic_setLoop(game->gamesong, sfTrue);
    sfMusic_setVolume(game->gamesong, 100);
    sfMusic_play(game->gamesong);
    return game;
}

void check_menu_buttons(game_object_t *game, button_t **menu_buttons)
{
    if (menu_buttons[1]->state == IS_CLICKED) {
        game->GAMESTATE = GAME;
        change_music_menu(game);
    }
    if (menu_buttons[3]->state == IS_CLICKED){
        game->GAMESTATE = END;
    }
    if (menu_buttons[8]->state == IS_CLICKED){
        game->GAMESTATE = SETTINGS;
    }
}

static void manage_click_menu(button_t **menu_buttons, sfEvent event)
{
    if (event.mouseButton.x >= 750 && event.mouseButton.y >= 360 &&
    event.mouseButton.x <= 1100 && event.mouseButton.y <= 490) {
        menu_buttons[1]->state = IS_CLICKED;
    }
    if (event.mouseButton.x >= 750 && event.mouseButton.y >= 500 &&
    event.mouseButton.x <= 1100 && event.mouseButton.y <= 630) {
        menu_buttons[3]->state = IS_CLICKED;
    }
    if (event.mouseButton.x >= 1350 && event.mouseButton.y >= 440 &&
    event.mouseButton.x <= 1700 && event.mouseButton.y <= 560) {
        menu_buttons[5]->state = IS_CLICKED;
    }
    if (event.mouseButton.x >= 150 && event.mouseButton.y >= 440 &&
    event.mouseButton.x <= 500 && event.mouseButton.y <= 560) {
        menu_buttons[8]->state = IS_CLICKED;
    }
}

void events_menu(game_object_t *game, button_t **menu_buttons)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(game->window->w, &event)) {
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyQ))
        game->GAMESTATE = END;
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyX)
        game->menubutton[5]->state = ISNT_CLICKED;
        if (event.type == sfEvtMouseButtonPressed &&
         event.mouseButton.button == sfMouseLeft) {
             manage_click_menu(menu_buttons, event);
         }
    }
}

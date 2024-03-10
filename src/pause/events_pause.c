/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** pause_events
*/
#include "myrpg.h"

void events_pause(button_t **pause_buttons, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft) {
        if (event.mouseButton.x >= 735 && event.mouseButton.y >= 200 &&
        event.mouseButton.x <= 1170 && event.mouseButton.y <= 300)
            pause_buttons[0]->state = IS_CLICKED;
        if (event.mouseButton.x >= 735 && event.mouseButton.y >= 350 &&
        event.mouseButton.x <= 1170 && event.mouseButton.y <= 450)
            pause_buttons[1]->state = IS_CLICKED;
        if (event.mouseButton.x >= 735 && event.mouseButton.y >= 525 &&
        event.mouseButton.x <= 1170 && event.mouseButton.y <= 640)
            pause_buttons[2]->state = IS_CLICKED;
        if (event.mouseButton.x >= 735 && event.mouseButton.y >= 690 &&
        event.mouseButton.x <= 1170 && event.mouseButton.y <= 820)
            pause_buttons[3]->state = IS_CLICKED;
    }
}

static button_t **start_chrono_pause(button_t **pause_buttons)
{
    start_chrono(pause_buttons[0]->chrono);
    start_chrono(pause_buttons[1]->chrono);
    start_chrono(pause_buttons[2]->chrono);
    start_chrono(pause_buttons[3]->chrono);
    return pause_buttons;
}

static void check_pause_buttons_bis(game_object_t *game, button_t
**pause_buttons)
{
    if (pause_buttons[2]->state == IS_CLICKED &&
    pause_buttons[2]->chrono->seconds > 0.5) {
        //clicked_home(game, pause_buttons);
        game->GAMESTATE = GAME;
        game->PAUSE = DO_NOT_EXIST;
    }
    if (pause_buttons[3]->state == IS_CLICKED &&
    pause_buttons[3]->chrono->seconds > 0.5) {
        clicked_quit(game, pause_buttons);
        game->GAMESTATE = END;
    }
}

void check_pause_buttons(game_object_t *game, button_t **pause_buttons)
{
    start_chrono_pause(pause_buttons);
    if (pause_buttons[0]->state == IS_CLICKED &&
    pause_buttons[0]->chrono->seconds > 0.5) {
        clicked_resume(game, pause_buttons);
        game->GAMESTATE = GAME;
        game->PAUSE = DO_NOT_EXIST;
    }
    if (pause_buttons[1]->state == IS_CLICKED &&
    pause_buttons[1]->chrono->seconds > 0.5) {
        clicked_settings(game, pause_buttons);
        game->prev_state = PAUSE;
        game->GAMESTATE = SETTINGS;
        game->PAUSE = DO_NOT_EXIST;
        reset_buttons_settings(game->settingsbutton);
    }
    check_pause_buttons_bis(game, pause_buttons);
}

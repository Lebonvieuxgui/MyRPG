/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** pause_engine
*/

#include "myrpg.h"

static void input_pause(game_object_t *game, sfEvent event)
{
    if (!game)
        return;
    if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyQ))
        game->GAMESTATE = END;
    if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)) {
        game->GAMESTATE = GAME;
        game->PAUSE = DO_NOT_EXIST;
    }
    events_pause(game->pausebutton, event);
    check_pause_buttons(game, game->pausebutton);
}

void manage_event_pause(game_object_t *game)
{
    sfEvent event;

    if (!game)
        return;
    while (sfRenderWindow_pollEvent(game->window->w, &event)) {
        input_pause(game, event);
    }
}

button_t **reset_buttons_pause(button_t **pause_buttons)
{
    pause_buttons[0]->state = ISNT_CLICKED;
    pause_buttons[1]->state = ISNT_CLICKED;
    pause_buttons[2]->state = ISNT_CLICKED;
    pause_buttons[3]->state = ISNT_CLICKED;
    return pause_buttons;
}

game_object_t *pause_engine(game_object_t *game)
{
    sfRenderWindow_setMouseCursorVisible(game->window->w, sfTrue);
    display_pause(game, game->pausebutton);
    check_hover_pause(game, game->pausebutton);
    manage_event_pause(game);
    reset_buttons_pause(game->pausebutton);
    sfRenderWindow_display(game->window->w);
    return game;
}

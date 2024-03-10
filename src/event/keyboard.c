/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** keyboard
*/
#include "myrpg.h"

static void tp(player_t *player, int x, int y)
{
    player->coord.x = x;
    player->coord.y = y;
}

static void tpbis(game_object_t *game, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI)
        tp(game->player, 2300, 300);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyO)
        tp(game->player, 4900, 460);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyU)
        tp(game->player, 320, 1100);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM)
        tp(game->player, 7300, 3800);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS
    && game->GAMESTATE == INTRO)
        tp(game->player, 300, 400);
}

void keyboard_input_event(game_object_t *game, sfEvent event)
{
    if (!game)
        return;
    if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyQ))
        game->GAMESTATE = END;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        game->GAMESTATE = PAUSE;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
        tp(game->player, 6000, 3400);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyK)
        tp(game->player, 4500, 3600);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyJ)
        tp(game->player, 2900, 3300);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
        tp(game->player, 6400, 400);
    tpbis(game, event);
}

/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** principal function
*/
#include "myrpg.h"

static void game_core(game_object_t *game)
{
    if (game->GAMESTATE == MENU)
        menu_engine(game);
    if (game->GAMESTATE == PAUSE)
        pause_engine(game);
    if (game->GAMESTATE == SETTINGS)
        settings_engine(game);
    if (game->GAMESTATE == INTRO)
        intro_engine(game);
    if (game->GAMESTATE == GAME)
        game_engine(game);
    if (game->GAMESTATE == BOSS)
        boss_engine(game);
    if (game->GAMESTATE == GAMEOVER)
        game_over_engine(game);
    if (game->GAMESTATE == END)
        sfRenderWindow_close(game->window->w);
}

int my_rpg(void)
{
    game_object_t *game = NULL;

    if (check_rsrce() == 84) {
        my_putstr("Some resources are missing to launch the game\n");
        return 84;
    }
    game = create_game();
    if (!game)
        return 84;
    while (sfRenderWindow_isOpen(game->window->w)) {
        game_core(game);
    }
    main_destroy(game);
    return 0;
}

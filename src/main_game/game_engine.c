/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** game_engine
*/

#include "myrpg.h"

static game_object_t *change_boss(game_object_t *game)
{
    if (game->player->coord.x < 2750 && game->player->coord.y > 3240
    && game->GAMESTATE != BOSS) {
        sfMusic_destroy(game->gamesong);
        game->gamesong = sfMusic_createFromFile("Rsrce/TheSongOfTheSword.ogg");
        game->GAMESTATE = BOSS;
        sfMusic_setLoop(game->gamesong, sfTrue);
        sfMusic_setVolume(game->gamesong, game->volume_music);
        sfMusic_play(game->gamesong);
    }
    return game;
}

game_object_t *game_engine(game_object_t *game)
{
    sfRenderWindow_clear(game->window->w, sfBlack);
    sfRenderWindow_setMouseCursorVisible(game->window->w, sfFalse);
    gest_chrono_hud_knight(game->HUD->HUD);
    manage_event(game);
    main_game(game);
    gest_view(game);
    change_boss(game);
    sfRenderWindow_display(game->window->w);
    return game;
}

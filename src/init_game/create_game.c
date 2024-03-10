/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** runner function who calls everything
*/
#include "myrpg.h"

static void set_positions(game_object_t *game)
{
    sfVector2f coord;

    if (game->wall != NULL && game->hallway != NULL) {
        coord.x = 2848;
        coord.y = 3310;
        sfSprite_setPosition(game->wall, coord);
        coord.x = -1469;
        coord.y = 200;
        sfSprite_setPosition(game->hallway, coord);
    }
}

static game_object_t *create_gamebis(game_object_t *game)
{
    game->GAMESTATE = MENU;
    game->PAUSE = DO_NOT_EXIST;
    game->GAMEOVER = DO_NOT_EXIST_GO;
    game->pause = create_sprite("Rsrce/Pause.png");
    game->wall = create_sprite("Rsrce/Wall.png");
    game->hallway = create_sprite("Rsrce/Hallway.png");
    game->darken = create_sprite("Rsrce/Darken.png");
    game->settings = create_sprite("Rsrce/menu_settings.png");
    game->gamesong = sfMusic_createFromFile("Rsrce/Menu.ogg");
    game->hitbox = sfImage_createFromFile("Rsrce/maphitbox.png");
    game->red = create_sprite("Rsrce/Red.png");
    create_hud(game);
    init_hearts(game);
    set_positions(game);
    sfMusic_play(game->gamesong);
    sfMusic_setLoop(game->gamesong, sfTrue);
    game->volume_music = 100;
    sfMusic_setVolume(game->gamesong, game->volume_music);
    game->sign = init_signs();
    game->doorframes = init_doorframes(game);
    game->gameover = init_game_over();
    game->doors = init_doors();
    return game;
}

static game_object_t *set_view(game_object_t *game)
{
    sfVector2f view_coord;

    view_coord.x = game->player->coord.x + 92;
    view_coord.y = game->player->coord.y + 92;
    sfView_setCenter(game->view, view_coord);
    return game;
}

game_object_t *create_game(void)
{
    game_object_t *game = malloc(sizeof(game_object_t));

    if (!game)
        return NULL;
    create_gamebis(game);
    game->objects = create_objects();
    game->window = create_window();
    game->view = create_view();
    game->map = create_map();
    game->player = create_player();
    game->nb_enemies = 53;
    game->prev_state = MENU;
    game->list_enemies = create_list_enemies(game);
    game->nemesis = create_nemesis();
    game->menubutton = create_menu_buttons();
    game->pausebutton = create_pause_buttons();
    game->settingsbutton = create_settings_buttons();
    game->fire = create_fire();
    game->deathcount = create_death_count(game);
    set_view(game);
    return game;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** move_camera
*/
#include "myrpg.h"

static int set_speed(game_object_t *game)
{
    if (!game)
        return 0;
    if ((game->coord_view.x < game->player->coord.x - 400
    || game->coord_view.x > game->player->coord.x + 400)
    || (game->coord_view.y < game->player->coord.y - 400
    || game->coord_view.y > game->player->coord.y + 400))
        return 3;
    if ((game->coord_view.x < game->player->coord.x - 200
    || game->coord_view.x > game->player->coord.x + 200)
    || (game->coord_view.y < game->player->coord.y - 200
    || game->coord_view.y > game->player->coord.y + 200))
        return 2;
    return 1;
}

static game_object_t *move_vertical(game_object_t *game)
{
    int speed = set_speed(game);

    if (!game || speed == 0)
        return NULL;
    if (game->coord_view.y != game->player->coord.y + 92) {
        if (game->coord_view.y < game->player->coord.y + 92)
            game->coord_view.y = game->coord_view.y + speed;
        else
            game->coord_view.y = game->coord_view.y - speed;
    }
    return game;
}

static game_object_t *move_horizontal(game_object_t *game)
{
    int speed = set_speed(game);

    if (!game || speed == 0)
        return NULL;
    if ((game->coord_view.x < game->player->coord.x - 500
    || game->coord_view.x > game->player->coord.x + 500)
    || (game->coord_view.y < game->player->coord.y - 500
    || game->coord_view.y > game->player->coord.y + 500))
        speed = 3;
    if (game->coord_view.x != game->player->coord.x + 92) {
        if (game->coord_view.x < game->player->coord.x + 92)
            game->coord_view.x = game->coord_view.x + speed;
        else
            game->coord_view.x = game->coord_view.x - speed;
    }
    return game;
}

game_object_t *move_camera(game_object_t *game)
{
    if (!game)
        return NULL;
    game->coord_view = sfView_getCenter(game->view);
    move_horizontal(game);
    move_vertical(game);
    sfView_setCenter(game->view, game->coord_view);
    return game;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** print_hud
*/

#include "myrpg.h"

static void set_pos_lives(game_object_t *game)
{
    game->HUD->live[0]->pos.y = game->coord_view.y + 365;
    game->HUD->live[0]->pos.x = game->coord_view.x - 700;
    game->HUD->live[1]->pos.y = game->coord_view.y + 365;
    game->HUD->live[1]->pos.x = game->coord_view.x - 650;
    game->HUD->live[2]->pos.y = game->coord_view.y + 365;
    game->HUD->live[2]->pos.x = game->coord_view.x - 600;
    game->HUD->live[3]->pos.y = game->coord_view.y + 365;
    game->HUD->live[3]->pos.x = game->coord_view.x - 550;
    game->HUD->live[4]->pos.y = game->coord_view.y + 365;
    game->HUD->live[4]->pos.x = game->coord_view.x - 500;
    game->HUD->live[5]->pos.y = game->coord_view.y + 365;
    game->HUD->live[5]->pos.x = game->coord_view.x - 450;
    sfSprite_setPosition(game->HUD->live[0]->sprite, game->HUD->live[0]->pos);
    sfSprite_setPosition(game->HUD->live[1]->sprite, game->HUD->live[1]->pos);
    sfSprite_setPosition(game->HUD->live[2]->sprite, game->HUD->live[2]->pos);
    sfSprite_setPosition(game->HUD->live[3]->sprite, game->HUD->live[3]->pos);
    sfSprite_setPosition(game->HUD->live[4]->sprite, game->HUD->live[4]->pos);
    sfSprite_setPosition(game->HUD->live[5]->sprite, game->HUD->live[5]->pos);
}

void print_lives(game_object_t *game)
{
    set_pos_lives(game);
    if (game->player->life >= 1)
        sfRenderWindow_drawSprite(game->window->w, game->HUD->live[0]->sprite,
        NULL);
    if (game->player->life >= 2)
        sfRenderWindow_drawSprite(game->window->w, game->HUD->live[1]->sprite,
        NULL);
    if (game->player->life >= 3)
        sfRenderWindow_drawSprite(game->window->w, game->HUD->live[2]->sprite,
        NULL);
    if (game->player->life >= 4)
        sfRenderWindow_drawSprite(game->window->w, game->HUD->live[3]->sprite,
        NULL);
    if (game->player->life >= 5)
        sfRenderWindow_drawSprite(game->window->w, game->HUD->live[4]->sprite,
        NULL);
    if (game->player->life >= 6)
        sfRenderWindow_drawSprite(game->window->w, game->HUD->live[5]->sprite,
        NULL);
}

static void set_pos_hud(game_object_t *game)
{
    game->HUD->HUD->pos.y = game->coord_view.y + 340;
    game->HUD->HUD->pos.x = game->coord_view.x - 958;
    game->HUD->frame->pos.y = game->coord_view.y + 338;
    game->HUD->frame->pos.x = game->coord_view.x - 958;
    game->HUD->board->pos.y = game->coord_view.y + 338;
    game->HUD->board->pos.x = game->coord_view.x - 758;
    sfSprite_setPosition(game->HUD->HUD->sprite, game->HUD->HUD->pos);
    sfSprite_setPosition(game->HUD->frame->sprite, game->HUD->frame->pos);
    sfSprite_setPosition(game->HUD->board->sprite, game->HUD->board->pos);
}

void print_HUD(game_object_t *game)
{
    set_pos_hud(game);
    set_pos_keys(game);
    sfRenderWindow_drawSprite(game->window->w, game->HUD->HUD->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->w, game->HUD->frame->sprite, NULL);
    sfRenderWindow_drawSprite(game->window->w, game->HUD->board->sprite, NULL);
    print_lives(game);
    print_keys(game);
    print_dash(game);
    print_block(game);
    death_count_engine(game, game->deathcount);
}
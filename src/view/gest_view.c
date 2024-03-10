/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** gest_view
*/
#include "myrpg.h"

static void nemesis_sprite_coord(game_object_t *game)
{
    if (game->player->coord.y - 80 >= game->nemesis->coord.y)
        sfRenderWindow_drawSprite(game->window->w, game->nemesis->sprite,
        NULL);
    sfRenderWindow_drawSprite(game->window->w, game->player->sprite, NULL);
    if (game->player->coord.y - 80 <= game->nemesis->coord.y)
        sfRenderWindow_drawSprite(game->window->w, game->nemesis->sprite,
        NULL);
}

static void draw_particles(game_object_t *game, particle_t **list_particles)
{
    int i = 0;

    while (i < 50) {
        if (list_particles[i]->activated == sfTrue) {
            sfRenderWindow_drawRectangleShape(game->window->w,
            list_particles[i]->rectangle, NULL);
        }
        i = i + 1;
    }
}

static game_object_t *gest_display(game_object_t *game)
{
    if (!game)
        return NULL;
    draw_particles(game, game->player->list_particles);
    for (int i = 0; i < game->nb_enemies; i += 1) {
        if (game->player->coord.y - 25 >= game->list_enemies[i]->coord.y) {
            sfRenderWindow_drawSprite(game->window->w,
            game->list_enemies[i]->sprite, NULL);
            print_hearts(game, i);
        }
    }
    nemesis_sprite_coord(game);
    display_doors(game);
    for (int i = 0; i < game->nb_enemies; i += 1) {
        if (game->player->coord.y - 25 <= game->list_enemies[i]->coord.y) {
            print_hearts(game, i);
            sfRenderWindow_drawSprite(game->window->w,
            game->list_enemies[i]->sprite, NULL);
        }
        taking_hearts(game, i);
    }
    return game;
}

static game_object_t *additionnal_display(game_object_t *game)
{
    display_rocks(game, game->list_enemies, game->nb_enemies);
    display_projos(game, game->nemesis->list_projos);
    print_HUD(game);
    display_sign(game);
    if (game->GAMESTATE == BOSS)
        sfRenderWindow_drawSprite(game->window->w,
        game->wall, NULL);
    return game;
}

game_object_t *gest_view(game_object_t *game)
{
    if (!game)
        return NULL;
    coord_view(game);
    if (game->GAMESTATE == INTRO && game->hallway != NULL)
        sfRenderWindow_drawSprite(game->window->w,
        game->hallway, NULL);
    gest_display(game);
    additionnal_display(game);
    return game;
}

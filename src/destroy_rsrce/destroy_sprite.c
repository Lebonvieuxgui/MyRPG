/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** destroy_sprite
*/

#include "myrpg.h"

static void destroy_hud_sprite(game_object_t *game)
{
    if (!game)
        return;
    sfSprite_destroy(game->HUD->HUD->sprite);
    sfSprite_destroy(game->HUD->frame->sprite);
    sfSprite_destroy(game->HUD->board->sprite);
    for (int i = 0; game->HUD->live[i] != NULL; i++)
        sfSprite_destroy(game->HUD->live[i]->sprite);
    for (int i = 0; game->HUD->key[i] != NULL; i++)
        sfSprite_destroy(game->HUD->key[i]->sprite);
    sfSprite_destroy(game->HUD->dash->sprite);
    sfSprite_destroy(game->HUD->block->sprite);
}

void destroy_sprite(game_object_t *game)
{
    if (!game)
        return;
    for (int i = 0; game->doors[i] != NULL; i++)
        sfSprite_destroy(game->doors[i]->sprite);
    destroy_hud_sprite(game);
    sfSprite_destroy(game->nemesis->sprite);
    sfSprite_destroy(game->player->sprite);
    sfSprite_destroy(game->fire->sprite);
    sfSprite_destroy(game->darken);
    sfSprite_destroy(game->pause);
    sfSprite_destroy(game->map);
}

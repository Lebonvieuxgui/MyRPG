/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** destroy_texture
*/

#include "myrpg.h"

static void destroy_hud_texture(game_object_t *game)
{
    if (!game)
        return;
    sfTexture_destroy(game->HUD->HUD->texture);
    sfTexture_destroy(game->HUD->frame->texture);
    sfTexture_destroy(game->HUD->board->texture);
    sfTexture_destroy(game->HUD->dash->texture);
    sfTexture_destroy(game->HUD->block->texture);
}

void destroy_texture(game_object_t *game)
{
    if (!game)
        return;
    destroy_hud_texture(game);
    sfTexture_destroy(game->nemesis->text);
    sfTexture_destroy(game->player->text);
    sfTexture_destroy(game->fire->texture);
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** hud_block
*/

#include "myrpg.h"

void print_block(game_object_t *game)
{
    game->HUD->block->pos.x = game->coord_view.x - 530;
    game->HUD->block->pos.y = game->coord_view.y + 430;
    sfSprite_setPosition(game->HUD->block->sprite, game->HUD->block->pos);
    if (game->objects[5]->taked == sfTrue)
        sfRenderWindow_drawSprite(game->window->w, game->HUD->block->sprite,
        NULL);
}

button_t *create_hud_block(void)
{
    button_t *block = malloc(sizeof(button_t));

    if (!block)
        return NULL;
    block->texture = sfTexture_createFromFile("Rsrce/block_medal_solo.png",
    NULL);
    block->sprite = sfSprite_create();
    sfSprite_setTexture(block->sprite, block->texture, sfFalse);
    return block;
}
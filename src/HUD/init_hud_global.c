/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** init_frame_global
*/

#include "myrpg.h"

button_t *create_medal_button(void)
{
    button_t *medal = malloc(sizeof(button_t));

    if (!medal)
        return NULL;
    medal->texture = sfTexture_createFromFile("Rsrce/dash_medal_solo.png",
    NULL);
    medal->sprite = sfSprite_create();
    sfSprite_setTexture(medal->sprite, medal->texture, sfFalse);
    return medal;
}

void create_hud(game_object_t *game)
{
    game->HUD = malloc(sizeof(hud_t));
    game->HUD->HUD = create_hud_knight();
    game->HUD->frame = create_hud_frame();
    game->HUD->board = create_hud_board();
    game->HUD->live = create_hud_heart();
    game->HUD->key = create_hud_key();
    game->HUD->dash = create_medal_button();
    game->HUD->block = create_hud_block();
}

button_t *create_hud_frame()
{
    button_t *frame = malloc(sizeof(button_t));

    if (!frame)
        return NULL;
    frame->texture = sfTexture_createFromFile("Rsrce/frame.png", NULL);
    frame->sprite = sfSprite_create();
    sfSprite_setTexture(frame->sprite, frame->texture, sfFalse);
    return frame;
}

button_t *create_hud_board()
{
    button_t *board = malloc(sizeof(button_t));

    if (!board)
        return NULL;
    board->texture = sfTexture_createFromFile("Rsrce/Hudboard.png", NULL);
    board->sprite = sfSprite_create();
    sfSprite_setTexture(board->sprite, board->texture, sfFalse);
    return board;
}

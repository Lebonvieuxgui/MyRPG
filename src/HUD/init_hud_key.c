/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** init_hud_key
*/

#include "myrpg.h"

void print_keys(game_object_t *game)
{
    if (game->objects[1]->taked == sfTrue)
        sfRenderWindow_drawSprite(game->window->w, game->HUD->key[0]->sprite,
        NULL);
    if (game->objects[2]->taked == sfTrue)
        sfRenderWindow_drawSprite(game->window->w, game->HUD->key[1]->sprite,
        NULL);
    if (game->objects[3]->taked == sfTrue)
        sfRenderWindow_drawSprite(game->window->w, game->HUD->key[2]->sprite,
        NULL);
    if (game->objects[4]->taked == sfTrue)
        sfRenderWindow_drawSprite(game->window->w, game->HUD->key[3]->sprite,
        NULL);
}

static void set_pos_keys_next(game_object_t *game)
{
    game->HUD->key[0]->pos.x = game->coord_view.x - 695;
    game->HUD->key[0]->pos.y = game->coord_view.y + 420;
    game->HUD->key[0]->scale.x = 0.8;
    game->HUD->key[0]->scale.y = 0.8;
    game->HUD->key[1]->pos.x = game->coord_view.x - 660;
    game->HUD->key[1]->pos.y = game->coord_view.y + 420;
    game->HUD->key[1]->scale.x = 0.8;
    game->HUD->key[1]->scale.y = 0.8;
    game->HUD->key[2]->pos.x = game->coord_view.x - 625;
    game->HUD->key[2]->pos.y = game->coord_view.y + 420;
    game->HUD->key[2]->scale.x = 0.8;
    game->HUD->key[2]->scale.y = 0.8;
    game->HUD->key[3]->pos.x = game->coord_view.x - 590;
    game->HUD->key[3]->pos.y = game->coord_view.y + 420;
    game->HUD->key[3]->scale.x = 0.8;
    game->HUD->key[3]->scale.y = 0.8;
}

void set_pos_keys(game_object_t *game)
{
    set_pos_keys_next(game);
    sfSprite_setPosition(game->HUD->key[0]->sprite, game->HUD->key[0]->pos);
    sfSprite_setScale(game->HUD->key[0]->sprite, game->HUD->key[0]->scale);
    sfSprite_setPosition(game->HUD->key[1]->sprite, game->HUD->key[1]->pos);
    sfSprite_setScale(game->HUD->key[1]->sprite, game->HUD->key[1]->scale);
    sfSprite_setPosition(game->HUD->key[2]->sprite, game->HUD->key[2]->pos);
    sfSprite_setScale(game->HUD->key[2]->sprite, game->HUD->key[2]->scale);
    sfSprite_setPosition(game->HUD->key[3]->sprite, game->HUD->key[3]->pos);
    sfSprite_setScale(game->HUD->key[3]->sprite, game->HUD->key[3]->scale);
}

button_t **create_hud_key(void)
{
    button_t **keys = malloc(sizeof(button_t) * 5);

    if (keys == NULL)
        return NULL;
    keys[0] = malloc(sizeof(button_t));
    keys[0]->sprite = create_sprite("Rsrce/cléverte.png");
    keys[1] = malloc(sizeof(button_t));
    keys[1]->sprite = create_sprite("Rsrce/clébleue.png");
    keys[2] = malloc(sizeof(button_t));
    keys[2]->sprite = create_sprite("Rsrce/cléjaune.png");
    keys[3] = malloc(sizeof(button_t));
    keys[3]->sprite = create_sprite("Rsrce/clérouge.png");
    keys[4] = NULL;
    return keys;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** sign
*/

#include "myrpg.h"

button_t **init_signs()
{
    button_t **sign = malloc(sizeof(button_t)* 4);

    if (!sign)
        return NULL;
    sign[0] = malloc(sizeof(button_t));
    sign[0]->sprite = create_sprite("Rsrce/pannel.png");
    sign[1] = malloc(sizeof(button_t));
    sign[1]->sprite = create_sprite("Rsrce/panneldash.png");
    sign[2] = malloc(sizeof(button_t));
    sign[2]->sprite = create_sprite("Rsrce/pannelblock.png");
    sign[3] = NULL;
    return sign;
}

static void display_sign_abilities(game_object_t *game, sfVector2f position)
{
    if (game->player->coord.x > 4500 && game->player->coord.x < 4700
        && game->player->coord.y > 3300 && game->player->coord.y < 3460
        && sfKeyboard_isKeyPressed(sfKeyX)) {
            sfSprite_setPosition(game->sign[1]->sprite, position);
            sfRenderWindow_drawSprite(game->window->w,
            game->sign[1]->sprite, NULL);
        }
    if (game->player->coord.x > 4200 && game->player->coord.x < 4400
        && game->player->coord.y > 400 && game->player->coord.y < 660
        && sfKeyboard_isKeyPressed(sfKeyX)) {
            sfSprite_setPosition(game->sign[2]->sprite, position);
            sfRenderWindow_drawSprite(game->window->w,
            game->sign[2]->sprite, NULL);
        }
}

void display_sign(game_object_t *game)
{
    sfVector2f position;

    position.x = game->coord_view.x - 960;
    position.y = game->coord_view.y - 540;
    if (game->player->coord.x > 150 && game->player->coord.x < 300
        && game->player->coord.y > 20 && game->player->coord.y < 350
        && sfKeyboard_isKeyPressed(sfKeyX)) {
            sfSprite_setPosition(game->sign[0]->sprite, position);
            sfRenderWindow_drawSprite(game->window->w,
            game->sign[0]->sprite, NULL);
        }
    display_sign_abilities(game, position);
}

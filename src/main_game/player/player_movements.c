/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** player_movements
*/
#include "myrpg.h"

player_t *right_direction(player_t *player)
{
    player->direction = RIGHT;
    if (player->direction != player->ancient_direction
    || player->state != MOVING) {
        player->rect.left = 0;
        player->rect.top = 1344;
        player->ancient_direction = player->direction;
        player->state = MOVING;
    }
    player->moved = sfTrue;
    if (!sfKeyboard_isKeyPressed(sfKeyDown)
    && !sfKeyboard_isKeyPressed(sfKeyUp))
        player->coord.x = player->coord.x + 4;
    else
        player->coord.x = player->coord.x + 3;
    sfSprite_setPosition(player->sprite, player->coord);
    sfSprite_setTexture(player->sprite, player->text, sfFalse);
    return player;
}

player_t *left_direction(player_t *player)
{
    player->direction = LEFT;
    if (player->direction != player->ancient_direction
    || player->state != MOVING) {
        player->rect.left = 0;
        player->rect.top = 1152;
        player->ancient_direction = player->direction;
        player->state = MOVING;
    }
    player->moved = sfTrue;
    if (!sfKeyboard_isKeyPressed(sfKeyDown)
    && !sfKeyboard_isKeyPressed(sfKeyUp))
        player->coord.x = player->coord.x - 4;
    else
        player->coord.x = player->coord.x - 3;
    sfSprite_setPosition(player->sprite, player->coord);
    sfSprite_setTexture(player->sprite, player->text, sfFalse);
    return player;
}

player_t *up_direction(player_t *player)
{
    player->direction = UP;
    if ((player->direction != player->ancient_direction
    || player->state != MOVING)
    && !sfKeyboard_isKeyPressed(sfKeyLeft)
    && !sfKeyboard_isKeyPressed(sfKeyRight)) {
        player->rect.left = 0;
        player->rect.top = 960;
        player->ancient_direction = player->direction;
        player->state = MOVING;
    }
    player->moved = sfTrue;
    if (!sfKeyboard_isKeyPressed(sfKeyLeft)
    && !sfKeyboard_isKeyPressed(sfKeyRight))
        player->coord.y = player->coord.y - 4;
    else
        player->coord.y = player->coord.y - 3;
    sfSprite_setPosition(player->sprite, player->coord);
    sfSprite_setTexture(player->sprite, player->text, sfFalse);
    return player;
}

player_t *down_direction(player_t *player)
{
    player->direction = DOWN;
    if ((player->direction != player->ancient_direction
    || player->state != MOVING)
    && !sfKeyboard_isKeyPressed(sfKeyLeft)
    && !sfKeyboard_isKeyPressed(sfKeyRight)) {
        player->rect.left = 0;
        player->rect.top = 768;
        player->ancient_direction = player->direction;
        player->state = MOVING;
    }
    player->moved = sfTrue;
    if (!sfKeyboard_isKeyPressed(sfKeyLeft)
    && !sfKeyboard_isKeyPressed(sfKeyRight))
        player->coord.y = player->coord.y + 4;
    else
        player->coord.y = player->coord.y + 3;
    sfSprite_setPosition(player->sprite, player->coord);
    sfSprite_setTexture(player->sprite, player->text, sfFalse);
    return player;
}

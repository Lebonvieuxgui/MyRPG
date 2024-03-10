/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** player_stop
*/
#include "myrpg.h"

player_t *stop_right(player_t *player)
{
    player->state = IDLE;
    player->rect.top = 576;
    sfSprite_setTexture(player->sprite, player->text, sfFalse);
    return player;
}

player_t *stop_left(player_t *player)
{
    player->state = IDLE;
    player->rect.top = 384;
    sfSprite_setTexture(player->sprite, player->text, sfFalse);
    return player;
}

player_t *stop_up(player_t *player)
{
    player->state = IDLE;
    player->rect.top = 192;
    sfSprite_setTexture(player->sprite, player->text, sfFalse);
    return player;
}

player_t *stop_down(player_t *player)
{
    player->state = IDLE;
    player->rect.top = 0;
    sfSprite_setTexture(player->sprite, player->text, sfFalse);
    return player;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** death_player
*/
#include "myrpg.h"

player_t *player_end(player_t *player)
{
    if (player->dead == sfTrue && player->state != DEAD) {
        if (player->direction == DOWN)
            player->rect.top = 3072;
        if (player->direction == UP)
            player->rect.top = 3264;
        if (player->direction == LEFT)
            player->rect.top = 3456;
        if (player->direction == RIGHT)
            player->rect.top = 3648;
        sfSprite_setTextureRect(player->sprite, player->rect);
    }
    return player;
}

player_t *death_player(player_t *player)
{
    if (player->life <= 0 && player->dead == sfFalse) {
        player->dead = sfTrue;
        player->state = DEAD;
        if (player->direction == DOWN)
            player->rect.top = 3072;
        if (player->direction == UP)
            player->rect.top = 3264;
        if (player->direction == LEFT)
            player->rect.top = 3456;
        if (player->direction == RIGHT)
            player->rect.top = 3648;
        player->rect.left = 0;
        sfSprite_setTextureRect(player->sprite, player->rect);
    }
    return player;
}

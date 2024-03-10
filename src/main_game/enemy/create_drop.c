/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** create_drop
*/

#include "myrpg.h"

button_t **drop_heart(enemy_t *enemy, button_t **heart, int i)
{
    sfVector2f pos;

    pos.x = enemy->coord.x + 55;
    pos.y = enemy->coord.y + 30;
    if (rand() % 3 == 1) {
        if (heart[i] != NULL) {
            heart[i]->pos = enemy->coord;
            heart[i]->state = IS_CLICKED;
            heart[i]->pos = pos;
        }
    }
    return heart;
}

static sfSound **create_sounds_heart(void)
{
    sfSound **sounds = malloc(sizeof(sfSound *) * 1);

    sounds[0] = sfSound_create();
    sfSound_setBuffer(sounds[0], \
    sfSoundBuffer_createFromFile("Rsrce/heal.ogg"));
    sfSound_setVolume(sounds[0], 50);
    return sounds;
}

static button_t *init_heart(game_object_t *game, int i)
{
    game->heart[i] = malloc(sizeof(button_t));
    if(!game->heart[i])
        return NULL;
    game->heart[i]->sprite = create_sprite("Rsrce/heartsprite2.png");
    game->heart[i]->chrono = create_chrono();
    game->heart[i]->rect.height = 99;
    game->heart[i]->rect.width = 39;
    game->heart[i]->sounds = create_sounds_heart();
    game->heart[i]->rect.top = 0;
    game->heart[i]->rect.left = 0;
    game->heart[i]->pos.x = 0;
    game->heart[i]->pos.y = 0;
    game->heart[i]->state = ISNT_CLICKED;
    sfSprite_setTextureRect(game->heart[i]->sprite, game->heart[i]->rect);
    return game->heart[i];
}

button_t **init_hearts(game_object_t *game)
{
    int i = 0;

    game->heart = malloc(sizeof(button_t)* 200);
    while (i < 200) {
        init_heart(game, i);
        i += 1;
    }
    return game->heart;
}

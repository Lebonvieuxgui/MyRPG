/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** init_doors
*/

#include "myrpg.h"

static button_t *init_green_door(void)
{
    button_t *greendoor = malloc(sizeof(object_t));

    greendoor->texture = sfTexture_createFromFile("Rsrce/porteverte.png", NULL);
    greendoor->sprite = sfSprite_create();
    greendoor->pos.x = 2432;
    greendoor->pos.y = 952;
    greendoor->scale.x = 0.5;
    greendoor->scale.y = 0.5;
    sfSprite_setPosition(greendoor->sprite, greendoor->pos);
    sfSprite_setTexture(greendoor->sprite, greendoor->texture, sfFalse);
    sfSprite_setScale(greendoor->sprite, greendoor->scale);
    return greendoor;
}

static button_t *init_blue_door(void)
{
    button_t *bluedoor = malloc(sizeof(object_t));

    bluedoor->texture = sfTexture_createFromFile("Rsrce/portebleue.png", NULL);
    bluedoor->sprite = sfSprite_create();
    bluedoor->pos.x = 7222;
    bluedoor->pos.y = 812;
    bluedoor->scale.x = 0.5;
    bluedoor->scale.y = 0.5;
    sfSprite_setPosition(bluedoor->sprite, bluedoor->pos);
    sfSprite_setTexture(bluedoor->sprite, bluedoor->texture, sfFalse);
    sfSprite_setScale(bluedoor->sprite, bluedoor->scale);
    return bluedoor;
}

static button_t *init_yellow_door(void)
{
    button_t *yellowdoor = malloc(sizeof(object_t));

    yellowdoor->texture = sfTexture_createFromFile("Rsrce/portejaune.png", NULL);
    yellowdoor->sprite = sfSprite_create();
    yellowdoor->pos.x = 5902;
    yellowdoor->pos.y = 2431;
    yellowdoor->scale.x = 0.5;
    yellowdoor->scale.y = 0.5;
    sfSprite_setPosition(yellowdoor->sprite, yellowdoor->pos);
    sfSprite_setTexture(yellowdoor->sprite, yellowdoor->texture, sfFalse);
    sfSprite_setScale(yellowdoor->sprite, yellowdoor->scale);
    return yellowdoor;
}

static button_t *init_red_door(void)
{
    button_t *reddoor = malloc(sizeof(object_t));

    reddoor->texture = sfTexture_createFromFile("Rsrce/porterouge.png", NULL);
    reddoor->sprite = sfSprite_create();
    reddoor->pos.x = 3152;
    reddoor->pos.y = 2202;
    reddoor->scale.x = 0.5;
    reddoor->scale.y = 0.5;
    sfSprite_setPosition(reddoor->sprite, reddoor->pos);
    sfSprite_setTexture(reddoor->sprite, reddoor->texture, sfFalse);
    sfSprite_setScale(reddoor->sprite, reddoor->scale);
    return reddoor;
}

button_t **init_doors(void)
{
    button_t **doors = malloc(sizeof(button_t) * 5);

    doors[0] = init_green_door();
    doors[1] = init_blue_door();
    doors[2] = init_yellow_door();
    doors[3] = init_red_door();
    doors[4] = NULL;
    return doors;
}

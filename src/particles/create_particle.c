/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** create_rectangle
*/
#include "myrpg.h"

particle_t *set_coordinate_particle(player_t *player, particle_t *particle)
{
    if (player->direction == DOWN) {
        particle->coord.y = player->coord.y + 120;
        particle->coord.x = player->coord.x + ((rand() % (110 - 70)) + 70);
    }
    if (player->direction == UP) {
        particle->coord.y = player->coord.y + 160;
        particle->coord.x = player->coord.x + ((rand() % (110 - 70)) + 70);
    }
    if (player->direction == LEFT) {
        particle->coord.y = player->coord.y + ((rand() % (160 - 140)) + 140);
        particle->coord.x = player->coord.x + 110;
    }
    if (player->direction == RIGHT) {
        particle->coord.y = player->coord.y + ((rand() % (160 - 140)) + 140);
        particle->coord.x = player->coord.x + 70;
    }
    return particle;
}

particle_t *create_particle(void)
{
    particle_t *particle = malloc(sizeof(particle_t));
    sfVector2f size;

    size.x = 5;
    size.y = 5;
    srand(time(NULL));
    particle->activated = sfFalse;
    particle->coord.x = -1000;
    particle->coord.y = -1000;
    particle->launch_coord = particle->coord;
    particle->direction = DOWN;
    particle->chrono.clock = sfClock_create();
    particle->rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(particle->rectangle, size);
    sfRectangleShape_setPosition(particle->rectangle, particle->coord);
    sfRectangleShape_setFillColor(particle->rectangle, sfWhite);
    return particle;
}

particle_t **create_list_particles(void)
{
    particle_t **list_particles = malloc(sizeof(particle_t) * 50);
    int i = 0;

    while (i < 50) {
        list_particles[i] = create_particle();
        i = i + 1;
    }
    list_particles[i] = NULL;
    return list_particles;
}

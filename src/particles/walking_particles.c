/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** walking_particles
*/
#include "myrpg.h"

static particle_t *check_particle(particle_t *particle)
{
    if ((particle->coord.x < particle->launch_coord.x -
    ((rand() % (50 - 5)) + 5)
    || particle->coord.x > particle->launch_coord.x +
    ((rand() % (50 - 5)) + 5))
    || (particle->coord.y < particle->launch_coord.y -
    ((rand() % (50 - 5)) + 5)
    || particle->coord.y > particle->launch_coord.y +
    ((rand() % (50 - 5)) + 5))) {
        particle->activated = sfFalse;
    }
    return particle;
}

static void choose_direction_particle(particle_t *particle)
{
    if (particle->direction == DOWN)
        particle->coord.y = particle->coord.y - 1;
    if (particle->direction == UP)
        particle->coord.y = particle->coord.y + 1;
    if (particle->direction == LEFT)
        particle->coord.x = particle->coord.x + 1;
    if (particle->direction == RIGHT)
        particle->coord.x = particle->coord.x - 1;
    sfRectangleShape_setPosition(particle->rectangle,
    particle->coord);
}

static particle_t **move_particles(particle_t **list_particles)
{
    int i = 0;

    while (i < 50) {
        list_particles[i]->chrono =
        get_chrono(list_particles[i]->chrono);
        if (list_particles[i]->activated == sfTrue &&
        list_particles[i]->chrono.seconds > 0.1) {
            choose_direction_particle(list_particles[i]);
            check_particle(list_particles[i]);
            sfClock_restart(list_particles[i]->chrono.clock);
        }
        i = i + 1;
    }
    return list_particles;
}

static particle_t *activate_particle(player_t *player, particle_t *particle)
{
    set_coordinate_particle(player, particle);
    particle->activated = sfTrue;
    particle->direction = player->direction;
    particle->launch_coord = particle->coord;
    sfRectangleShape_setPosition(particle->rectangle, particle->coord);
    return particle;
}

void walking_particles(player_t *player)
{
    static int i = 0;

    if (i >= 50)
        i = 0;
    player->chrono_particles = get_chrono(player->chrono_particles);
    if (player->state == MOVING && player->chrono_particles.seconds > 0.25) {
        activate_particle(player, player->list_particles[i]);
        sfClock_restart(player->chrono_particles.clock);
        i = i + 1;
    }
    move_particles(player->list_particles);
}

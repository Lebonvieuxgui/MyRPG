/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** manage_rocks
*/
#include "myrpg.h"

static projectile_t *trajectory_rock(game_object_t *game, projectile_t *rock)
{
    if (rock->direction == DOWN && collision_down_rock(game, rock) == 0)
        rock->coord.y = rock->coord.y + 16;
    if (rock->direction == UP && collision_up_rock(game, rock) == 0)
        rock->coord.y = rock->coord.y - 16;
    if (rock->direction == LEFT && collision_left_rock(game, rock) == 0)
        rock->coord.x = rock->coord.x - 16;
    if (rock->direction == RIGHT && collision_right_rock(game, rock) == 0)
        rock->coord.x = rock->coord.x + 16;
    sfSprite_setPosition(rock->sprite, rock->coord);
    return rock;
}

static projectile_t *collision_rock(enemy_t *slinger, projectile_t *rock,
player_t *player)
{
    if ((rock->coord.x + 19 > player->coord.x + 30
    && rock->coord.x + 19 < player->coord.x + 90)
    && (rock->coord.y + 20 > player->coord.y + 30
    && rock->coord.y + 20 < player->coord.y + 160)
    && player->state != DASHING) {
        rock->coord.x = -1000;
        rock->coord.y = -1000;
        rock->launched = sfFalse;
        touched_player(slinger, player);
    }
    return rock;
}

static enemy_t *move_rocks(game_object_t *game, enemy_t *slinger,
player_t *player)
{
    int i = 0;

    while (i < 10) {
        slinger->list_rocks[i]->chrono_mov =
        get_chrono(slinger->list_rocks[i]->chrono_mov);
        if (slinger->list_rocks[i]->chrono_mov.seconds > 0.0000001
        && slinger->list_rocks[i]->launched == sfTrue) {
            trajectory_rock(game, slinger->list_rocks[i]);
            collision_rock(slinger, slinger->list_rocks[i], player);
            sfClock_restart(slinger->list_rocks[i]->
            chrono_mov.clock);
        }
        i = i + 1;
    }
    return slinger;
}

enemy_t **manage_rocks(game_object_t *game, enemy_t **list_enemies,
player_t *player, int nb_enemies)
{
    int i = 0;

    while (i < nb_enemies) {
        if (list_enemies[i]->type == SLINGER
        && list_enemies[i]->state == ATTACKING)
            launch_rock(list_enemies[i]);
        if (list_enemies[i]->type == SLINGER)
            move_rocks(game, list_enemies[i], player);
        i = i + 1;
    }
    return list_enemies;
}

/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** header
*/
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/Window/Sensor.h>
#include <SFML/System/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include "enum.h"
#include "my.h"

#ifndef MY_DEFENDER
    #define MY_DEFENDER

    #define MENU_START "src/game_asset/menu/start.jpg"
    #define ERROR 84
    #define FAILURE 1
    #define SUCCESS 0

typedef struct Chrono_s
{
    sfTime time;
    float seconds;
    sfClock *clock;
} Chrono_t;

typedef struct particle_s
{
    sfRectangleShape *rectangle;
    enum direction direction;
    sfVector2f launch_coord;
    sfBool activated;
    sfVector2f coord;
    Chrono_t chrono;
} particle_t;

typedef struct projectile_s {
    enum direction direction;
    Chrono_t chrono_launch;
    Chrono_t chrono_anim;
    Chrono_t chrono_mov;
    sfVector2f coord;
    sfVector2f scale;
    sfSprite *sprite;
    sfTexture *text;
    sfBool launched;
    sfIntRect rect;
} projectile_t;

typedef struct boss_s {
    projectile_t **list_projos;
    Chrono_t chrono_knockback;
    enum direction direction;
    Chrono_t chrono_sounds;
    Chrono_t chrono_jump;
    Chrono_t chrono_anim;
    Chrono_t Chrono_wait;
    Chrono_t chrono_mov;
    sfVector2f coord;
    sfSprite *sprite;
    enum state state;
    sfSound **sounds;
    sfTexture *text;
    sfIntRect rect;
    sfBool touched;
    sfBool dead;
    int life;
} boss_t;

typedef struct object_s {
    Chrono_t chrono_anim;
    sfVector2f coord;
    sfVector2f scale;
    sfSprite *sprite;
    sfTexture *text;
    sfIntRect rect;
    sfSound *sound;
    sfBool taked;
} object_t;

typedef struct enemy_s {
    Chrono_t chrono_knockback;
    projectile_t **list_rocks;
    enum direction direction;
    Chrono_t chrono_anim;
    Chrono_t chrono_sounds;
    enum enemy_type type;
    Chrono_t chrono_mov;
    sfVector2f coord;
    sfSprite *sprite;
    enum state state;
    sfSound **sounds;
    sfTexture *text;
    sfIntRect rect;
    sfBool touched;
    sfBool dead;
    int rock;
    int life;
} enemy_t;

typedef struct player_s {
    enum direction ancient_direction;
    particle_t **list_particles;
    Chrono_t chrono_knockback;
    Chrono_t chrono_particles;
    enum direction direction;
    enum direction pushback;
    Chrono_t chrono_sounds;
    Chrono_t chrono_skill;
    Chrono_t chrono_dash;
    Chrono_t chrono_anim;
    Chrono_t chrono_mov;
    sfVector2f coord;
    sfSprite *sprite;
    enum state state;
    sfSound **sounds;
    sfTexture *text;
    sfIntRect rect;
    sfBool moved;
    sfBool block;
    sfBool dash;
    sfBool dead;
    int life;
    int nb_deaths;
} player_t;

typedef struct text_s {
    int nb;
    sfFont *font;
    sfText *text;
    sfText *title;
} text_t;

typedef struct my_window_s{
    sfRenderWindow *w;
    sfVideoMode mode;
    sfEvent event;
    int height;
    int width;
    int framelimit;
} my_window_t;

typedef struct game_clock_s {
    float seconds;
    sfTime time;
    sfClock *clock;
} game_clock_t;

typedef struct button_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    game_clock_t *chrono;
    sfSound **sounds;
    enum state_button state;
} button_t;

typedef struct menu_s {
    sfSprite *background;
    sfFont *font;
    sfMusic *music;
} menu_t;

typedef struct hud_s {
    button_t *HUD;
    button_t *frame;
    button_t *board;
    button_t **live;
    button_t **key;
    button_t *dash;
    button_t *block;
} hud_t;

typedef struct game_s {
    game_clock_t clock_enemy;
    game_clock_t clock_tower;
    game_clock_t clock_button;
    enemy_t **list_enemies;
    sfVector2f coord_view;
    Chrono_t chrono_view;
    my_window_t *window;
    object_t **objects;
    sfMusic *gamesong;
    player_t *player;
    boss_t *nemesis;
    int nb_enemies;
    int volume_music;
    int prev_state;
    text_t *coins;
    sfSprite *map;
    sfSprite *pause;
    sfSprite *settings;
    sfSprite *darken;
    sfSprite *wall;
    sfSprite *hallway;
    sfSprite *red;
    sfView *view;
    text_t *shop;
    menu_t *menu;
    button_t **menubutton;
    button_t **pausebutton;
    button_t **settingsbutton;
    button_t **heart;
    button_t *fire;
    button_t **sign;
    button_t **doors;
    button_t **doorframes;
    button_t **gameover;
    button_t **deathcount;
    sfImage *hitbox;
    hud_t *HUD;
    enum GAMESTATE GAMESTATE;
    enum PAUSE PAUSE;
    enum GAMEOVER GAMEOVER;
} game_object_t;

int main(int const argc, char const * const *argv, char **env);
int check_arg(int const argc, char const * const *argv);
int check_env(char **env);
void my_put_h(void);
int my_rpg(void);

enemy_t **manage_rocks(game_object_t *game, enemy_t **list_enemies,
player_t *player, int nb_enemies);
void display_rocks(game_object_t *game, enemy_t **list_enemies,
int nb_enemies);
game_object_t *intro_engine(game_object_t *game);
int collision_right_rock(game_object_t *game, projectile_t *rock);
int collision_left_rock(game_object_t *game, projectile_t *rock);
int collision_up_rock(game_object_t *game, projectile_t *rock);
int collision_down_rock(game_object_t *game, projectile_t *rock);
enemy_t **manage_enemy(enemy_t **list_enemy, player_t *player, int nb_enemys,
game_object_t *game);
enemy_t **place_room1(enemy_t **list_enemies);
enemy_t **place_room2(enemy_t **list_enemies);
int collision_right_enemy(game_object_t *game, enemy_t *enemy);
int collision_left_enemy(game_object_t *game, enemy_t *enemy);
int collision_up_enemy(game_object_t *game, enemy_t *enemy);
int collision_down_enemy(game_object_t *game, enemy_t *enemy);
enemy_t **lose_focus(enemy_t **list_enemys, player_t *player, int nb_enemys);
enemy_t *choose_direction_enemy(enemy_t *enemy, player_t *player);
object_t **is_yellow_taked(object_t **objects, player_t *player);
object_t **is_green_taked(object_t **objects, player_t *player);
object_t **is_blue_taked(object_t **objects, player_t *player);
object_t **is_red_taked(object_t **objects, player_t *player);
int is_blocked_nemesis(player_t *player, boss_t *nemesis);
enemy_t *touched_enemy(enemy_t *enemy, player_t *player);
void launch_jumpjo(boss_t *nemesis);
int detect_player(enemy_t *enemy, player_t *player);
object_t *key_yellow_animation(object_t *yellowkey);
enemy_t **create_list_enemies(game_object_t *game);
int attack_range(enemy_t *enemy, player_t *player);
object_t *key_green_animation(object_t *greenkey);
game_object_t *key_animation(game_object_t *game);
game_clock_t initialize_clock(game_clock_t clock);
enemy_t **create_list_enemys(game_object_t *game);
void init_create_game_clock(game_object_t *game);
int is_blocked(player_t *player, enemy_t *enemy);
game_object_t *boss_engine(game_object_t *game);
object_t *key_blue_animation(object_t *bluekey);
game_object_t *player_boss(game_object_t *game);
game_object_t *move_camera(game_object_t *game);
game_object_t *coord_view(game_object_t *game);
game_object_t *gest_view(game_object_t *game);
object_t *key_red_animation(object_t *redkey);
void launch_game_clock(game_object_t *game);
void init_create_music(game_object_t *game);
player_t *block_animation(player_t *player);
player_t *knockback_block(game_object_t *game, player_t *player);
void init_create_menu(game_object_t *game);
object_t *medal_animation(object_t *medal);
player_t *dash_animation(game_object_t *game, player_t *player);
object_t **taked_keys(game_object_t *game);
player_t *sounds_player(player_t *player);
player_t *block_player(player_t *player);
void create_texture(game_object_t *game);
sfSprite *create_sprite(char *texture);
enemy_t *create_possesed(int x, int y);
player_t *player_end(player_t *player);
player_t *stop_right(player_t *player);
void set_pos_keys(game_object_t *game);
void set_texture(game_object_t *game);
player_t *stop_down(player_t *player);
player_t *stop_left(player_t *player);
void print_block(game_object_t *game);
void init_texte(game_object_t *game);
void print_keys(game_object_t *game);
void print_dash(game_object_t *game);
button_t *create_medal_button(void);
player_t *stop_up(player_t *player);
object_t *create_block_medal(void);
object_t *create_dash_medal(void);
game_clock_t *create_chrono(void);
game_object_t *create_game(void);
my_window_t *create_window(void);
button_t *create_hud_block(void);
object_t **create_objects(void);
object_t *init_yellow_key(void);
button_t **create_hud_key(void);
object_t *init_green_key(void);
object_t *init_blue_key(void);
player_t *create_player(void);
object_t *init_red_key(void);
enemy_t *create_enemy(void);
sfSprite *create_map(void);
sfView *create_view(void);
button_t **init_hearts(game_object_t *game);
button_t **drop_heart(enemy_t *enemy, button_t **heart, int i);
button_t **taking_hearts(game_object_t *game, int i);
void print_hearts(game_object_t *game, int i);
void display_sign(game_object_t *game);
button_t **init_signs(void);
boss_t *move_projos_nemesis(game_object_t *game, boss_t *nemesis,
player_t *player);
object_t **taked_objects(object_t **objects, player_t *player);
void keyboard_input_event(game_object_t *game, sfEvent event);
void close_window_event(game_object_t *game, sfEvent *event);
game_object_t *game_engine(game_object_t *game);
player_t *movement_player(game_object_t *game);
void manage_event(game_object_t *game);
game_object_t **create_menu_button(game_object_t *game);
button_t **create_menu_buttons(void);
void events_menu(game_object_t *game, button_t **menu_buttons);
button_t **reset_buttons_pause(button_t **pause_buttons);
button_t **reset_buttons_settings(button_t **settings_buttons);
void display_projos(game_object_t *game, projectile_t **list_projos);
void hover_menu(game_object_t *game, button_t **menu_buttons);
game_object_t *menu_engine(game_object_t *game);
button_t *create_fire(void);
button_t *gest_chrono_fire(button_t *fire);
void check_menu_buttons(game_object_t *game, button_t **menu_buttons);
void start_chrono(game_clock_t *chrono);
int move_rect_enemy(sfIntRect rect, int value, int offset, int max_value);
game_object_t *htp_engine(game_object_t *game, button_t **button);
int collision_down_projo(game_object_t *game, projectile_t *projo);
int collision_up_projo(game_object_t *game, projectile_t *projo);
int collision_left_projo(game_object_t *game, projectile_t *projo);
int collision_right_projo(game_object_t *game, projectile_t *projo);
enemy_t **enemy_animation(game_object_t *game, enemy_t **list_enemy,
player_t *player, int nb_enemys);
enemy_t **detect_attack_player(enemy_t **list_enemy, player_t *player, int nb);
player_t *detect_attack_enemy(enemy_t **list_enemy, player_t *player, int nb);
player_t *touched_player_nemesis(boss_t *nemesis, player_t *player);
enemy_t **reduce_life_enemy(enemy_t **list_enemys, int nb_enemys);
enemy_t *return_idle_enemy(enemy_t *enemy, player_t *player);
enemy_t **death_enemy(game_object_t *game, enemy_t **list_enemys,
int nb_enemys);
player_t *touched_player(enemy_t *enemy, player_t *player);
enemy_t *knockback_enemy(game_object_t *game,
enemy_t *enemy, player_t *player);
enemy_t *close_distance(game_object_t *game, enemy_t *enemy, player_t *player);
int in_range_for_possesed(enemy_t *enemy, player_t *player);
int attack_range_possesed(player_t *player, enemy_t *enemy);
enemy_t *attack_possesed(enemy_t *enemy, player_t *player);
int in_range_for_slinger(enemy_t *enemy, player_t *player);
enemy_t *attack_slinger(enemy_t *enemy, player_t *player);
enemy_t *close_distance_slinger(game_object_t *game, enemy_t *enemy,
player_t *player);
player_t *attack_player_nemesis(player_t *player);
player_t *reduce_life_player(player_t *player);
Chrono_t get_clock_enemy(Chrono_t chrono_mov);
game_object_t *main_game(game_object_t *game);
player_t *player_animation(player_t *player, game_object_t *game);
player_t *knockback_player(game_object_t *game, player_t *player);
player_t *right_direction(player_t *player);
enemy_t **place_room3(enemy_t **list_enemies);
enemy_t **place_room4(enemy_t **list_enemies);
player_t *down_direction(player_t *player);
player_t *left_direction(player_t *player);
player_t *attack_player(player_t *player);
player_t *death_player(player_t *player);
player_t *up_direction(player_t *player);
player_t *dash_player(player_t *player);
player_t *player_stop(player_t *player);
player_t *return_idle(player_t *player);
enemy_t *launch_rock(enemy_t *slinger);
Chrono_t get_chrono(Chrono_t chrono);

button_t **init_game_over();
game_object_t *game_over_engine(game_object_t *game);
void events_gameover(game_object_t *game, button_t **gameover);
void check_go_buttons(game_object_t *game, button_t **gameover);
void check_hover_go(game_object_t *game, button_t **gameover);
button_t **create_death_count(game_object_t *game);
void death_count_engine(game_object_t *game, button_t **deathcount);

boss_t *detect_attack_player_nemesis(boss_t *nemesis, player_t *player);
boss_t *jumptack_nemesis_animation(boss_t *nemesis, player_t *player);
boss_t *choose_direction_nemesis(boss_t *nemesis, player_t *player);
boss_t *jumpjo_nemesis_animation(boss_t *nemesis, player_t *player);
player_t *detect_attack_nemesis(boss_t *nemesis, player_t *player);
boss_t *wait_jumpjo_nemesis(boss_t *nemesis);
boss_t *lose_focus_nemesis(boss_t *nemesis, player_t *player);
int detect_player_nemesis(boss_t *nemesis, player_t *player);
boss_t *knockback_nemesis(boss_t *nemesis, player_t *player);
int attack_range_nemesis(player_t *player, boss_t *nemesis);
boss_t *touched_nemesis(boss_t *nemesis, player_t *player);
boss_t *attack_nemesis(boss_t *nemesis, player_t *player);
boss_t *jumpjo_nemesis(boss_t *nemesis);
int zonetack_nemesis(boss_t *nemesis, player_t *player);
boss_t *move_nemesis(game_object_t *game, boss_t *nemesis, player_t *player);
int collision_right_nemesis(game_object_t *game, boss_t *nemesis);
int collision_down_nemesis(game_object_t *game, boss_t *nemesis);
int collision_left_nemesis(game_object_t *game, boss_t *nemesis);
int collision_up_nemesis(game_object_t *game, boss_t *nemesis);
int in_range_nemesis(boss_t *nemesis, player_t *player);
boss_t *wait_nemesis(boss_t *nemesis, float wait_time);
int jump_trajectory(boss_t *nemesis, sfVector2f goal);
boss_t *animation_nemesis_jumptack(boss_t *nemesis);
int jump_right(boss_t *nemesis, sfVector2f goal);
boss_t *jump_nemesis_animation(boss_t *nemesis);
int jump_down(boss_t *nemesis, sfVector2f goal);
int jump_left(boss_t *nemesis, sfVector2f goal);
boss_t *wait_jumptack_nemesis(boss_t *nemesis);
int jump_up(boss_t *nemesis, sfVector2f goal);
boss_t *return_idle_nemesis(boss_t *nemesis);
boss_t *reduce_life_nemesis(boss_t *nemesis);
boss_t *wait_jump_nemesis(boss_t *nemesis);
boss_t *animation_nemesis(boss_t *nemesis);
boss_t *sounds_nemesis(boss_t *nemesis);
boss_t *projo_nemesis(boss_t *nemesis);
boss_t *death_nemesis(boss_t *nemesis);
enemy_t *create_slinger(int x, int y);
boss_t *jump_nemesis(boss_t *nemesis);
boss_t *create_nemesis(void);

void init_collision_engine(game_object_t *game);
int collision_down(game_object_t *game, int x, int y);
int collision_up(game_object_t *game, int x, int y);
int collision_left(game_object_t *game, int x, int y);
int collision_right(game_object_t *game, int x, int y);
int check_black_or_white(game_object_t *game, int x, int y);
void collision_engine(game_object_t *game);

game_object_t *pause_engine(game_object_t *game);
button_t **create_pause_buttons(void);
void display_pause(game_object_t *game, button_t **pause_buttons);
void check_hover_pause(game_object_t *game, button_t **pause_buttons);
void events_pause(button_t **pause_buttons, sfEvent event);
void check_pause_buttons(game_object_t *game, button_t **pause_buttons);
button_t **reset_buttons_pause(button_t **pause_buttons);
void clicked_resume(game_object_t *game, button_t **pause_buttons);
void clicked_settings(game_object_t *game, button_t **pause_buttons);
void clicked_home(game_object_t *game, button_t **pause_buttons);
void clicked_quit(game_object_t *game, button_t **pause_buttons);
game_clock_t *create_chrono(void);

void display_doors(game_object_t *game);
game_object_t *gest_view(game_object_t *game);
button_t **init_doors(void);
button_t **init_doorframes(game_object_t *game);

void draw_menu(game_object_t *game, button_t **menu_buttons);
game_object_t *settings_engine(game_object_t *game);
button_t **create_settings_buttons(void);
button_t *create_hud_knight(void);
button_t *create_hud_frame(void);
button_t *create_hud_board(void);
button_t *gest_chrono_hud_knight(button_t *HUD);
void print_HUD(game_object_t *game);
void create_hud(game_object_t *game);
button_t **create_hud_heart(void);
void print_lives(game_object_t *game);

particle_t *set_coordinate_particle(player_t *player, particle_t *particle);
void walking_particles(player_t *player);
particle_t **create_list_particles(void);
particle_t *create_particle(void);

void destroy_music(game_object_t *game, boss_t *nemesis, player_t *player);
void destroy_resource_and_free(game_object_t *game);
void free_game_object(game_object_t *game);
void destroy_texture(game_object_t *game);
void destroy_sprite(game_object_t *game);
void main_destroy(game_object_t *game);
int check_rsrce_menu_pause(void);
char *transform_score(int nb);
int check_rsrce_objects(void);
int check_rsrce_doors(void);
int check_rsrce_music(void);
int check_rsrce(void);

#endif

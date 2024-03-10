##
## EPITECH PROJECT, 2021
## my_rpg
## File description:
## makefile
##

SRC_MAIN = main.c

OBJ_MAIN = $(SRC_MAIN:.c=.o)

SRC	=	src/main_game/enemy/place_enemies/place_room1.c	\
		src/main_game/enemy/place_enemies/place_room2.c	\
		src/main_game/enemy/place_enemies/place_room3.c	\
		src/main_game/enemy/place_enemies/place_room4.c	\
		src/boss/nemesis/jump/calculate_trajectory.c	\
		src/main_game/enemy/close_distance_slinger.c	\
		src/main_game/enemy/close_distance_enemies.c	\
		src/boss/nemesis/collision_projos_nemesis.c		\
		src/boss/nemesis/jump/jumptack_nemesis.c		\
		src/main_game/player/player_movements.c			\
		src/boss/nemesis/jump/jump_trajectory.c			\
		src/main_game/player/player_animation.c			\
		src/main_game/player/movement_player.c			\
		src/main_game/player/knockback_block.c			\
		src/boss/nemesis/jump/jumpjo_nemesis.c			\
		src/main_game/enemy/enemy_animation.c			\
		src/main_game/player/stop_direction.c			\
		src/main_game/enemy/detection_enemy.c			\
		src/main_game/enemy/collision_enemy.c			\
		src/main_game/enemy/collision_rocks.c			\
		src/boss/nemesis/collision_nemesis.c			\
		src/boss/nemesis/jump/jump_nemesis.c			\
		src/main_game/player/create_player.c			\
		src/main_game/player/attack_player.c			\
		src/boss/nemesis/animation_nemesis.c			\
		src/main_game/enemy/choose_d_enemy.c			\
		src/main_game/player/detect_attack.c			\
		src/boss/nemesis/detection_nemesis.c			\
		src/main_game/player/sounds_player.c			\
		src/boss/nemesis/jump/wait_nemesis.c			\
		src/main_game/enemy/range_possesed.c			\
		src/boss/nemesis/trajectory_projos.c			\
		src/main_game/enemy/range_slinger.c				\
		src/boss/nemesis/zonetack_nemesis.c				\
		src/main_game/player/death_player.c				\
		src/main_game/player/block_player.c				\
		src/collision/collision_direction.c				\
		src/boss/nemesis/choose_direction.c				\
		src/destroy_rsrce/destroy_texture.c				\
		src/main_game/enemy/manage_rocks.c				\
		src/main_game/enemy/launch_rocks.c 				\
		src/main_game/enemy/create_enemy.c				\
		src/main_game/enemy/manage_enemy.c				\
		src/main_game/player/player_stop.c				\
		src/main_game/player/hurt_player.c				\
		src/main_game/enemy/attack_enemy.c				\
		src/main_game/player/dash_player.c				\
		src/main_game/enemy/heart_engine.c				\
		src/main_game/player/return_idle.c				\
		src/destroy_rsrce/destroy_sprite.c				\
		src/destroy_rsrce/destroy_music.c				\
		src/main_game/enemy/create_drop.c				\
		src/boss/nemesis/sounds_nemesis.c				\
		src/main_game/enemy/death_enemy.c				\
		src/particles/walking_particles.c				\
		src/boss/nemesis/create_nemesis.c				\
		src/boss/nemesis/attack_nemesis.c				\
		src/destroy_rsrce/main_destroy.c				\
		src/boss/nemesis/projo_nemesis.c				\
		src/boss/attack_player_nemesis.c				\
		src/error_handling/check_error.c				\
		src/boss/nemesis/range_nemesis.c				\
		src/main_game/enemy/hurt_enemy.c				\
		src/collision/collision_engine.c				\
		src/boss/nemesis/death_nemesis.c				\
		src/particles/create_particle.c					\
		src/boss/nemesis/move_nemesis.c					\
		src/boss/nemesis/hurt_nemesis.c					\
		src/boss/block_player_nemesis.c					\
		src/check_rsrce/check_objects.c					\
		src/settings/settings_engine.c					\
		src/gameover/events_gameover.c					\
		src/gameover/game_over_engine.c					\
		src/gameover/hover_game_over.c					\
		src/check_rsrce/check_pause.c					\
		src/check_rsrce/check_doors.c					\
		src/error_handling/my_put_h.c					\
		src/check_rsrce/check_music.c					\
		src/check_rsrce/check_rsrce.c					\
		src/settings/init_settings.c					\
		src/init_game/create_game.c						\
		src/main_game/game_engine.c						\
		src/main_game/player/sign.c						\
		src/init_game/block_medal.c						\
		src/init_game/dash_medal.c						\
		src/doors/display_doors.c						\
		src/pause/clicked_pause.c						\
		src/main_game/main_game.c						\
		src/pause/display_pause.c						\
		src/HUD/init_hud_knight.c						\
		src/HUD/init_hud_global.c						\
		src/gameover/game_over.c						\
		src/HUD/init_hud_lives.c						\
		src/intro/intro_engine.c						\
		src/event/manage_event.c						\
		src/pause/pause_engine.c						\
		src/pause/events_pause.c						\
		src/view/display_rocks.c						\
		src/HUD/print_dash_HUD.c						\
		src/menu/create_chrono.c						\
		src/pause/hover_pause.c							\
		src/doors/doorsframe.c							\
		src/doors/init_doors.c							\
		src/view/move_camera.c							\
		src/menu/events_menu.c							\
		src/menu/menu_engine.c							\
		src/init_game/window.c							\
		src/view/create_view.c							\
		src/boss/boss_engine.c							\
		src/boss/player_boss.c							\
		src/pause/init_pause.c							\
		src/doors/taked_keys.c							\
		src/doors/yellow_key.c							\
		src/HUD/init_hud_key.c							\
		src/HUD/death_count.c							\
		src/doors/green_key.c							\
		src/menu/hover_menu.c							\
		src/view/coord_view.c							\
		src/doors/blue_key.c							\
		src/menu/init_menu.c							\
		src/event/keyboard.c							\
		src/map/create_map.c							\
		src/view/gest_view.c							\
		src/menu/fire_menu.c							\
		src/HUD/print_hud.c								\
		src/HUD/hud_block.c								\
		src/doors/red_key.c								\
		src/create_score.c								\
		src/event/window.c								\
		lib/my_strncmp.c								\
		lib/my_putchar.c								\
		lib/my_putstr.c									\
		lib/my_strlen.c									\
		src/my_rpg.c

OBJ	=	$(SRC:.c=.o)

CFLAGS		+=	-Wextra -Wall
CPPFLAGS	+=	-I./include
CSFML		+=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CC=gcc

NAME	=	my_rpg

all:	decompress $(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS) $(CSFML) $(CPPFLAGS)

compress:
	tar -Jcvf archive.tar.xz Rsrce/

decompress:
	tar xvf archive.tar.xz

clean:
	$(RM) $(OBJ) $(OBJ_MAIN)
	$(RM) *~ *#

fclean:	clean
	$(RM) $(NAME)
	$(RM) -drf Rsrce/

re: fclean all

.PHONY: all clean fclean re

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** enum
*/

#ifndef ENUM_H_
    #define ENUM_H_

enum GAMESTATE {
    MENU,
    SETTINGS,
    INTRO,
    GAME,
    BOSS,
    HOME,
    PAUSE,
    GAMEOVER,
    END,
};

enum PAUSE {
    EXIST,
    DO_NOT_EXIST,
};

enum GAMEOVER {
    EXIST_GO,
    DO_NOT_EXIST_GO,
};

enum state_button
{
    ISNT_CLICKED,
    IS_CLICKED
};

enum enemy_type {
    POSSESED,
    SLINGER
};

enum state {
    IDLE,
    HURT,
    DEAD,
    MOVING,
    PROJO,
    DASHING,
    JUMPING,
    WAITING,
    BLOCKED,
    JUMPTACK,
    ZONETACK,
    BLOCKING,
    ATTACKING,
    JUMP_JUMPJO,
    HURT_NEMESIS,
    WAITING_JUMPJO,
    BLOCKED_NEMESIS,
    WAITING_JUMPTACK
};

enum direction {
    NONE,
    LEFT,
    RIGHT,
    DOWN,
    UP
};

#endif /* !ENUM_H_ */

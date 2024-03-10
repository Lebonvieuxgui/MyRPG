/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** check_pause
*/

#include "myrpg.h"

int check_rsrce_menu_pause(void)
{
    if (open("Rsrce/quitsprite.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/homesprite.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/resumesprite.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/settingssprite.png", O_RDONLY) == -1)
        return 84;
    return 0;
}

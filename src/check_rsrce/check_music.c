/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** check_music
*/

#include "myrpg.h"

int check_rsrce_music(void)
{
    if (open("Rsrce/catacombs.ogg", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/heal.ogg", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Menu.ogg", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Nemesis_Footstep.ogg", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Player_Footstep.ogg", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/TheSongOfTheSword.ogg", O_RDONLY) == -1)
        return 84;
    return 0;
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** check_objects
*/

#include "myrpg.h"

int check_rsrce_objects(void)
{
    if (open("Rsrce/dash_medal.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/greenkey.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/bluekey.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/yellowkey.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/redkey.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/block_medal.png", O_RDONLY) == -1)
        return 84;
    return 0;
}

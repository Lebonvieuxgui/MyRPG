/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** check_doors
*/

#include "myrpg.h"

int check_rsrce_doors(void)
{
    if (open("Rsrce/porte.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/porteverte.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/portebleue.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/portejaune.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/porterouge.png", O_RDONLY) == -1)
        return 84;
    return 0;
}

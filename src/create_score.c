/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** transform int to char *
*/
#include "myrpg.h"

char *transform_score(int nb)
{
    int nb_clone = nb;
    int tmp = 0;
    char *str = NULL;

    while (nb > 10) {
        tmp += 1;
        nb = nb / 10;
    }
    str = malloc(sizeof(char) * (tmp + 1));
    if (!str)
        return 0;
    while (tmp >= 0) {
        str[tmp] = (nb_clone % 10) + 48;
        nb_clone /= 10;
        tmp -= 1;
    }
    return str;
}

/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_strlen
*/
#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i += 1;
    }
    return (i);
}

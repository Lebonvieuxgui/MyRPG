/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_strncmp
*/
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int result = 0;
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && (i < n - 1))
        i += 1;
    result = s1[i] - s2[i];
    if (result == 0)
        return (0);
    if (result > 0)
        return (1);
    return (-1);
}

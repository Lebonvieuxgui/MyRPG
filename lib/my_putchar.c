/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_putchar
*/
#include "my.h"

void my_putchar(char const c)
{
    write(1, &c, 1);
}

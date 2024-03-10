/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main
*/
#include "myrpg.h"

int main(int const argc, char const * const *argv, char **env)
{
    if ((check_arg(argc, argv) == 84) || (check_env(env) == 84)) {
         return ERROR;
     }
    return my_rpg();
}

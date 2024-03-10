/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** error handling
*/
#include "myrpg.h"

int check_env(char **env)
{
    if (!env)
        return 84;
    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp(env[i], "DISPLAY=", 8) == 0)
            return 0;
    }
    return 84;
}

int check_arg(int const argc, char const * const *argv)
{
    if ((!argv) || (!argc))
        return 84;
    if (argc == 2 && (argv[1][0] == '-') && my_strlen(argv[1]) != 2) {
        my_putstr("Usage : ./my_rpg -h\n");
        return 84;
    }
    if (argc == 2 && my_strlen(argv[1]) == 2 && argv[1][0] == '-' && \
    argv[1][1] == 'h') {
        my_put_h();
        return ERROR;
    }
    if (argc > 2 || (argc == 2 && argv[1][0] != '-')) {
        my_putstr("Usage : ./my_rpg -h\n");
        return 84;
    }
    return 0;
}

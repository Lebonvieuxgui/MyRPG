/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** arg_handling
*/
#include "myrpg.h"

static void my_put_logo(void)
{
    my_putstr("\n\n+------------------------------------------------------");
    my_putstr("------+\n");
    my_putstr("|                                                      ");
    my_putstr("      |\n");
    my_putstr("| ▀████████▄█████▄ ▀██▀   ▀██▀");
    my_putstr("   ▀███▄███▀████████▄ ▄█▀█████ |\n");
    my_putstr("|   ██    ██    ██   ██   ▄█  ");
    my_putstr("     ██▀ ▀▀  ██   ▀██▄██  ██   |\n");
    my_putstr("|   ██    ██    ██    ██ ▄█   ");
    my_putstr("     ██      ██    ██▀█████▀   |\n");
    my_putstr("|   ██    ██    ██     ███    ");
    my_putstr("     ██      ██   ▄████        |\n");
    my_putstr("| ▄████  ████  ████▄   ▄█     ");
    my_putstr("   ▄████▄    ██████▀  ███████  |\n");
    my_putstr("|                    ▄█       ");
    my_putstr("             ██      █▀     ██ |\n");
    my_putstr("|                  ██▀        ");
    my_putstr("           ▄████▄    ██████▀   |\n");
}

static void my_put_h_bis(void)
{
    my_putstr("| but be careful, you are not alone in here...");
    my_putstr("               |\n");
    my_putstr("|                             ");
    my_putstr("                               |\n");
    my_putstr("| Controls:");
    my_putstr("                                                  |\n");
    my_putstr("| Movements : Arrow keys           Pause : Esc");
    my_putstr("               |\n");
    my_putstr("| Attack : Space                   Interact : X");
    my_putstr("              |\n");
    my_putstr("| Block : C                        Dash : D");
    my_putstr("                  |\n");
    my_putstr("+----------------------------");
    my_putstr("--------------------------------+\n\n");
}

void my_put_h(void)
{
    my_put_logo();
    my_putstr("|                                                      ");
    my_putstr("      |\n");
    my_putstr("|      Epitech project by G.LEBRETON,");
    my_putstr(" G.RAUX, A.TEBINI       |\n");
    my_putstr("|                                                      ");
    my_putstr("      |\n");
    my_putstr("| Goal of the game:                                      ");
    my_putstr("    |\n");
    my_putstr("| Welcome, my fellow knight,");
    my_putstr(" in this mighty dungeon.         |\n");
    my_putstr("| You are here to reclaim your gold,");
    my_putstr("                         |\n");
    my_put_h_bis();
}

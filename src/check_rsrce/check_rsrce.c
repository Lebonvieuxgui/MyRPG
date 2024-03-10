/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** check_rsrce
*/

#include "myrpg.h"

static int check_rsrce_game(void)
{
    if (open("Rsrce/rock.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Slinger.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Possesed.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Nemesis.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/heartsprite2.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/pannel.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/panneldash.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/pannelblock.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/maphitbox.png", O_RDONLY) == -1)
        return 84;
    return 0;
}

static int check_rsrce_menu(void)
{
    if (open("Rsrce/Pause.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Darken.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/menu_settings.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/start.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Exit.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Menu.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Howtoplay.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Htp.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/menusprite.png", O_RDONLY) == -1)
        return 84;
    return 0;
}

static int check_rsrce_HUD(void)
{
    if (open("Rsrce/block_medal_solo.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/dash_medal_solo.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/clébleue.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/cléjaune.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/clérouge.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/cléverte.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/frame.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Hudboard.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/heart.png", O_RDONLY) == -1)
        return 84;
    return 0;
}

int check_rsrce(void)
{
    if (check_rsrce_HUD() == 84 || check_rsrce_menu() == 84 ||
    check_rsrce_music() == 84 || check_rsrce_game() == 84 ||
    check_rsrce_menu_pause() == 84 || check_rsrce_objects() == 84)
        return 84;
    if (open("Rsrce/map.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Player.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/bloodblade.png", O_RDONLY) == -1)
        return 84;
    if (open("Rsrce/Hudknight.png", O_RDONLY) == -1)
        return 84;
    return 0;
}

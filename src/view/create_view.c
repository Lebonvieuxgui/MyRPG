/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** create_view
*/
#include "myrpg.h"

sfView *create_view(void)
{
    sfFloatRect rect_view;
    sfView *view;

    rect_view.top = 0;
    rect_view.left = 0;
    rect_view.width = 1920;
    rect_view.height = 1080;
    view = sfView_createFromRect(rect_view);
    return view;
}

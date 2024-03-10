/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-guillaume.lebreton
** File description:
** settings_engine
*/

#include "myrpg.h"

button_t **reset_buttons_settings(button_t **settings_buttons)
{
    sfVector2f scale;

    scale.x = 1;
    scale.y = 1;
    settings_buttons[0]->state = ISNT_CLICKED;
    settings_buttons[2]->state = ISNT_CLICKED;
    sfSprite_setScale(settings_buttons[2]->sprite, scale);
    settings_buttons[3]->state = ISNT_CLICKED;
    sfSprite_setScale(settings_buttons[3]->sprite, scale);
    settings_buttons[4]->state = ISNT_CLICKED;
    sfSprite_setScale(settings_buttons[4]->sprite, scale);
    settings_buttons[5]->state = ISNT_CLICKED;
    sfSprite_setScale(settings_buttons[5]->sprite, scale);
    settings_buttons[6]->state = ISNT_CLICKED;
    sfSprite_setScale(settings_buttons[6]->sprite, scale);
    settings_buttons[7]->state = ISNT_CLICKED;
    sfSprite_setScale(settings_buttons[7]->sprite, scale);
    return settings_buttons;
}

void check_hover_pause_settings(game_object_t *game, button_t **settings_buttons)
{
    sfVector2f pos;
    sfVector2f scale;
    sfVector2i m = sfMouse_getPositionRenderWindow(game->window->w);

    pos.x = game->coord_view.x - 210;
    pos.y = game->coord_view.y + 190;
    scale.x = 1.1;
    scale.y = 1.1;
    sfSprite_setPosition(settings_buttons[1]->sprite, pos);
    if ((m.x >= 790 && m.x <= 1200) && (m.y >= 690 && m.y <= 810))
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[1]->sprite, NULL);
    if ((m.x >= 630 && m.x <= 730) && (m.y >= 220 && m.y <= 320)) {
        sfSprite_setScale(settings_buttons[4]->sprite, scale);
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[4]->sprite, NULL);
    }
    if ((m.x >= 630 && m.x <= 730) && (m.y >= 380 && m.y <= 480)) {
        sfSprite_setScale(settings_buttons[3]->sprite, scale);
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[3]->sprite, NULL);
    }
    if ((m.x >= 630 && m.x <= 730) && (m.y >= 540 && m.y <= 640)) {
        sfSprite_setScale(settings_buttons[7]->sprite, scale);
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[7]->sprite, NULL);
    }
    if ((m.x >= 1190 && m.x <= 1290) && (m.y >= 220 && m.y <= 320)) {
        sfSprite_setScale(settings_buttons[5]->sprite, scale);
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[5]->sprite, NULL);
    }
    if ((m.x >= 1190 && m.x <= 1290) && (m.y >= 380 && m.y <= 480)) {
        sfSprite_setScale(settings_buttons[2]->sprite, scale);
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[2]->sprite, NULL);
    }
    if ((m.x >= 1190 && m.x <= 1290) && (m.y >= 540 && m.y <= 640)) {
        sfSprite_setScale(settings_buttons[6]->sprite, scale);
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[6]->sprite, NULL);
    }
}

void check_hover_menu_settings(game_object_t *game, button_t **settings_buttons)
{
    sfVector2f scale;
    sfVector2i m = sfMouse_getPositionRenderWindow(game->window->w);

    scale.x = 1.1;
    scale.y = 1.1;
    sfSprite_setPosition(settings_buttons[1]->sprite, (sfVector2f) {745, 735});
    if ((m.x >= 790 && m.x <= 1200) && (m.y >= 740 && m.y <= 860))
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[1]->sprite, NULL);
    if ((m.x >= 670 && m.x <= 770) && (m.y >= 270 && m.y <= 370)) {
        sfSprite_setScale(settings_buttons[4]->sprite, scale);
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[4]->sprite, NULL);
    }
    if ((m.x >= 670 && m.x <= 770) && (m.y >= 430 && m.y <= 530)) {
        sfSprite_setScale(settings_buttons[3]->sprite, scale);
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[3]->sprite, NULL);
    }
    if ((m.x >= 670 && m.x <= 770) && (m.y >= 590 && m.y <= 690)) {
        sfSprite_setScale(settings_buttons[7]->sprite, scale);
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[7]->sprite, NULL);
    }
    if ((m.x >= 1150 && m.x <= 1250) && (m.y >= 270 && m.y <= 370)) {
        sfSprite_setScale(settings_buttons[5]->sprite, scale);
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[5]->sprite, NULL);
    }
    if ((m.x >= 1150 && m.x <= 1250) && (m.y >= 430 && m.y <= 530)) {
        sfSprite_setScale(settings_buttons[2]->sprite, scale);
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[2]->sprite, NULL);
    }
    if ((m.x >= 1150 && m.x <= 1250) && (m.y >= 590 && m.y <= 690)) {
        sfSprite_setScale(settings_buttons[6]->sprite, scale);
        sfRenderWindow_drawSprite(game->window->w, settings_buttons[6]->sprite, NULL);
    }
}

void event_menu_settings(button_t **settings_buttons, sfEvent event)
{
    if (event.mouseButton.x >= 735 && event.mouseButton.y >= 690 &&
    event.mouseButton.x <= 1170 && event.mouseButton.y <= 820)
        settings_buttons[0]->state = IS_CLICKED;
    if (event.mouseButton.x >= 1150 && event.mouseButton.y >= 380 &&
    event.mouseButton.x <= 1290 && event.mouseButton.y <= 530)
        settings_buttons[2]->state = IS_CLICKED;
    if (event.mouseButton.x >= 630 && event.mouseButton.y >= 380 &&
    event.mouseButton.x <= 770 && event.mouseButton.y <= 530)
        settings_buttons[3]->state = IS_CLICKED;
    if (event.mouseButton.x >= 630 && event.mouseButton.y >= 220 &&
    event.mouseButton.x <= 770 && event.mouseButton.y <= 370)
        settings_buttons[4]->state = IS_CLICKED;
    if (event.mouseButton.x >= 1150 && event.mouseButton.y >= 220 &&
    event.mouseButton.x <= 1290 && event.mouseButton.y <= 370)
        settings_buttons[5]->state = IS_CLICKED;
    if (event.mouseButton.x >= 1150 && event.mouseButton.y >= 540 &&
    event.mouseButton.x <= 1290 && event.mouseButton.y <= 690)
        settings_buttons[6]->state = IS_CLICKED;
    if (event.mouseButton.x >= 630 && event.mouseButton.y >= 540 &&
    event.mouseButton.x <= 770 && event.mouseButton.y <= 690)
        settings_buttons[7]->state = IS_CLICKED;
}

void check_settings_button(game_object_t *game, button_t **settings_buttons)
{
    if (settings_buttons[0]->state == IS_CLICKED && game->prev_state == MENU)
        game->GAMESTATE = INTRO;
    if (settings_buttons[0]->state == IS_CLICKED && game->prev_state == PAUSE)
        game->GAMESTATE = GAME;
    if (settings_buttons[2]->state == IS_CLICKED && game->window->width < 1920)
        sfRenderWindow_setSize(game->window->w, (sfVector2u)
        {game->window->width += 275, game->window->height += 110});
    if (settings_buttons[3]->state == IS_CLICKED && game->window->width > 820)
        sfRenderWindow_setSize(game->window->w, (sfVector2u)
        {game->window->width -= 275, game->window->height -= 110});
    if (settings_buttons[4]->state == IS_CLICKED && game->volume_music > 0)
        sfMusic_setVolume(game->gamesong, game->volume_music -= 20);
    if (settings_buttons[5]->state == IS_CLICKED && game->volume_music < 100)
        sfMusic_setVolume(game->gamesong, game->volume_music += 20);
}

void display_menu_settings(game_object_t *game, button_t **settings_buttons)
{
    sfSprite_setPosition(game->settings, (sfVector2f) {550, 160});
    sfRenderWindow_drawSprite(game->window->w, game->settings, NULL);
    sfSprite_setPosition(settings_buttons[0]->sprite, (sfVector2f) {760, 740});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[0]->sprite, NULL);
    sfSprite_setPosition(settings_buttons[2]->sprite, (sfVector2f) {1150, 430});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[2]->sprite, NULL);
    sfSprite_setPosition(settings_buttons[4]->sprite, (sfVector2f) {670, 270});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[4]->sprite, NULL);
    sfSprite_setPosition(settings_buttons[5]->sprite, (sfVector2f) {1150, 270});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[5]->sprite, NULL);
    sfSprite_setPosition(settings_buttons[3]->sprite, (sfVector2f) {670, 430});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[3]->sprite, NULL);
    sfSprite_setPosition(settings_buttons[6]->sprite, (sfVector2f) {1150, 590});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[6]->sprite, NULL);
    sfSprite_setPosition(settings_buttons[7]->sprite, (sfVector2f) {670, 590});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[7]->sprite, NULL);
    check_settings_button(game, settings_buttons);
}

void display_pause_settings(game_object_t *game, button_t **settings_buttons)
{
    sfVector2f pos;

    pos.x = game->coord_view.x - 450;
    pos.y = game->coord_view.y - 450;
    sfSprite_setPosition(game->settings, pos);
    sfSprite_setScale(game->settings, (sfVector2f) {1.1, 1.1});
    sfRenderWindow_drawSprite(game->window->w, game->settings, NULL);
    sfSprite_setPosition(settings_buttons[0]->sprite, (sfVector2f) {pos.x + 250, pos.y + 648});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[0]->sprite, NULL);
    sfSprite_setPosition(settings_buttons[2]->sprite, (sfVector2f) {pos.x + 680, pos.y + 300});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[2]->sprite, NULL);
    sfSprite_setPosition(settings_buttons[4]->sprite, (sfVector2f) {pos.x + 120, pos.y + 130});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[4]->sprite, NULL);
    sfSprite_setPosition(settings_buttons[5]->sprite, (sfVector2f) {pos.x + 680, pos.y + 130});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[5]->sprite, NULL);
    sfSprite_setPosition(settings_buttons[3]->sprite, (sfVector2f) {pos.x + 120, pos.y + 300});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[3]->sprite, NULL);
    sfSprite_setPosition(settings_buttons[6]->sprite, (sfVector2f) {pos.x + 680, pos.y + 500});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[6]->sprite, NULL);
    sfSprite_setPosition(settings_buttons[7]->sprite, (sfVector2f) {pos.x + 120, pos.y + 500});
    sfRenderWindow_drawSprite(game->window->w, settings_buttons[7]->sprite, NULL);
    check_settings_button(game, settings_buttons);
}

void input_settings(game_object_t *game, sfEvent event)
{
    if (!game)
        return;
    if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyQ))
        game->GAMESTATE = END;
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft)
        event_menu_settings(game->settingsbutton, event);
}

void manage_event_settings(game_object_t *game)
{
    sfEvent event;

    if (!game)
        return;
    while (sfRenderWindow_pollEvent(game->window->w, &event)) {
        input_settings(game, event);
    }
}

game_object_t *settings_engine(game_object_t *game)
{
    sfRenderWindow_setMouseCursorVisible(game->window->w, sfTrue);
    if (game->prev_state == PAUSE){
        display_pause_settings(game, game->settingsbutton);
        check_hover_pause_settings(game, game->settingsbutton);
    } else {
        display_menu_settings(game, game->settingsbutton);
        check_hover_menu_settings(game, game->settingsbutton);
    }
    manage_event_settings(game);
    check_settings_button(game, game->settingsbutton);
    reset_buttons_settings(game->settingsbutton);
    sfRenderWindow_display(game->window->w);
    return game;
}

/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** normal_1920
*/

#include "rpg.h"
#include <stdio.h>

static void change_screen(rpg_t *rpg, int width, int height)
{
    sfRenderWindow_setVisible(rpg->window.window, sfFalse);
    sfVector2u size = {width, height};
    sfRenderWindow_setSize(rpg->window.window, size);
    sfView_setSize(rpg->view.view, (sfVector2f){size.x, size.y});
    sfView_setCenter(rpg->view.view, (sfVector2f){size.x / 2, size.y / 2});
    rpg->settings.button[8].state = RELEASED;
    sfRenderWindow_setVisible(rpg->window.window, sfTrue);

}

void small_screen_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->settings.button[2].is_clicked(rpg, &rpg->settings.button[2],
            &rpg->window.event.mouseButton)) {
                rpg->settings.screen.str = "800 x 600";
                sfText_setString(rpg->settings.txt[10].text,
                    rpg->settings.screen.str);
                change_screen(rpg, 800, 600);
                rpg->settings.button[2].state = RELEASED;
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->settings.button[2].is_hover(rpg, &rpg->settings.button[2],
            &rpg->window.event.mouseMove);
    }
}

void middle_screen_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->settings.button[1].is_clicked(rpg, &rpg->settings.button[1],
            &rpg->window.event.mouseButton)) {
                rpg->settings.screen.str = "1600 x 900";
                sfText_setString(rpg->settings.txt[10].text,
                    rpg->settings.screen.str);
                change_screen(rpg, 1600, 900);
                rpg->settings.button[1].state = RELEASED;
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->settings.button[1].is_hover(rpg, &rpg->settings.button[1],
            &rpg->window.event.mouseMove);
    }
}

void normal_screen_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->settings.button[0].is_clicked(rpg, &rpg->settings.button[0],
                &rpg->window.event.mouseButton)) {
                rpg->settings.screen.str = "1920 x 1080";
                sfText_setString(rpg->settings.txt[10].text,
                    rpg->settings.screen.str);
                change_screen(rpg, 1920, 1080);
                rpg->settings.button[0].state = RELEASED;
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->settings.button[0].is_hover(rpg, &rpg->settings.button[0],
            &rpg->window.event.mouseMove);
    }
}

void choose_screen_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        rpg->settings.button[8].is_clicked(rpg, &rpg->settings.button[8],
            &rpg->window.event.mouseButton);
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->settings.button[8].is_hover(rpg, &rpg->settings.button[8],
            &rpg->window.event.mouseMove);
    }
}

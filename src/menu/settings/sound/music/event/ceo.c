/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** ceo
*/

#include "rpg.h"
#include <stdio.h>

void music_on_button_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->settings.button[5].is_clicked(rpg, &rpg->settings.button[5],
            &rpg->window.event.mouseButton)) {
                printf("Hello World\n");
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->settings.button[5].is_hover(rpg, &rpg->settings.button[5],
            &rpg->window.event.mouseMove);
    }
}

void music_off_button_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->settings.button[6].is_clicked(rpg, &rpg->settings.button[6],
            &rpg->window.event.mouseButton)) {
                printf("Hello World\n");
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->settings.button[6].is_hover(rpg, &rpg->settings.button[6],
            &rpg->window.event.mouseMove);
    }
}

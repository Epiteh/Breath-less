/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** off
*/

#include "rpg.h"
#include <stdio.h>

void sfx_off_button_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->settings.button[4].is_clicked(rpg, &rpg->settings.button[4],
            &rpg->window.event.mouseButton)) {
                printf("Hello World\n");
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->settings.button[4].is_hover(rpg, &rpg->settings.button[4],
            &rpg->window.event.mouseMove);
    }
}

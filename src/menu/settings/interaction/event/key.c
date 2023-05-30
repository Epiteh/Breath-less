/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** key
*/

#include "rpg.h"
#include <stdio.h>

static void get_input(rpg_t *rpg, sfKeyCode keycode)
{
    char *str = my_calloc(2, sizeof(char));

    if (keycode >= 0 && keycode <= 25) {
        sfKeyCode alpha = (keycode + 65);
        rpg->settings.interaction_key = alpha;
        str[0] = rpg->settings.interaction_key;
        sfText_setString(rpg->settings.txt[9].text, str);
        rpg->settings.button[7].state = RELEASED;
    }
}

void interaction_key_button_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtKeyPressed &&
        rpg->settings.button[7].state == PRESSED) {
            get_input(rpg, rpg->window.event.key.code);
    }
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->settings.button[7].is_clicked(rpg, &rpg->settings.button[7],
            &rpg->window.event.mouseButton)) {

            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->settings.button[7].is_hover(rpg, &rpg->settings.button[7],
            &rpg->window.event.mouseMove);
    }
}

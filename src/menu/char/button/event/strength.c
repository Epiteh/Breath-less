/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** strength
*/

#include "rpg.h"
#include <stdio.h>

static void strength_handle_reset_skills(rpg_t *rpg, int i)
{
    for (int y = i; y < 10; y += 1) {
        rpg->creator.button[y].state = RELEASED;
        sfRectangleShape_setFillColor(rpg->creator.button[y].rect,
            rpg->creator.button[y].color.color);
    }
    if (i != 5) {
        rpg->creator.button[i].state = PRESSED;
        sfRectangleShape_setFillColor(rpg->creator.button[i].rect,
            rpg->creator.button[i].color.pressed_color);
    }
}

static void strength_creator_handle(rpg_t *rpg, int i)
{
    if (rpg->creator.button[i].is_clicked(rpg, &rpg->creator.button[i],
        &rpg->window.event.mouseButton)) {
        for (int y = i; y >= 5; y -= 1) {
            rpg->creator.button[y].state = PRESSED;
            sfRectangleShape_setFillColor(rpg->creator.button[y].rect,
                rpg->creator.button[y].color.pressed_color);
        }
    } else if (rpg->creator.button[i].is_clicked(rpg, &rpg->creator.button[i],
        &rpg->window.event.mouseButton) &&
            rpg->creator.button[i].state == PRESSED) {
        strength_handle_reset_skills(rpg, i);
    }
}

void strength_creator_event(rpg_t *rpg)
{
    for (int i = 5; i < 10; i += 1) {
        if (rpg->window.event.type == sfEvtMouseButtonPressed) {
            strength_creator_handle(rpg, i);
        }
        if (rpg->window.event.type == sfEvtMouseMoved) {
            rpg->creator.button[i].is_hover(rpg, &rpg->creator.button[i],
                &rpg->window.event.mouseMove);
        }
    }
}

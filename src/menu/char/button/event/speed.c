/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** speed
*/

#include "rpg.h"
#include <stdio.h>
#include <stdbool.h>

static void speed_handle_reset_skills(rpg_t *rpg, int i)
{
    for (int y = i; y < 5; y += 1) {
        rpg->creator.button[y].state = RELEASED;
        sfRectangleShape_setFillColor(rpg->creator.button[y].rect,
            rpg->creator.button[y].color.color);
    }
    if (i != 0) {
        rpg->creator.button[i].state = PRESSED;
        sfRectangleShape_setFillColor(rpg->creator.button[i].rect,
            rpg->creator.button[i].color.pressed_color);
    }
}

static void speed_creator_handle(rpg_t *rpg, int i)
{
    if (rpg->creator.button[i].is_clicked(rpg, &rpg->creator.button[i],
        &rpg->window.event.mouseButton)) {
        for (int y = i; y >= 0; y -= 1) {
            rpg->creator.button[y].state = PRESSED;
            sfRectangleShape_setFillColor(rpg->creator.button[y].rect,
                rpg->creator.button[y].color.pressed_color);
        }
    } else if (rpg->creator.button[i].is_clicked(rpg, &rpg->creator.button[i],
        &rpg->window.event.mouseButton) &&
            rpg->creator.button[i].state == PRESSED) {
        speed_handle_reset_skills(rpg, i);
    }
}

void speed_creator_event(rpg_t *rpg)
{
    for (int i = 0; i < 5; i += 1) {
        if (rpg->window.event.type == sfEvtMouseButtonPressed) {
            speed_creator_handle(rpg, i);
        }
        if (rpg->window.event.type == sfEvtMouseMoved) {
            rpg->creator.button[i].is_hover(rpg, &rpg->creator.button[i],
                &rpg->window.event.mouseMove);
        }
    }
}

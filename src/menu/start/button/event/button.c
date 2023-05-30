/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** credits
*/

#include "rpg.h"
#include <stdio.h>

void start_credits_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->start.button[3].is_clicked(rpg, &rpg->start.button[3],
            &rpg->window.event.mouseButton)) {
                printf("Hello World\n");
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->start.button[3].is_hover(rpg, &rpg->start.button[3],
            &rpg->window.event.mouseMove);
    }
}

void start_load_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->start.button[1].is_clicked(rpg, &rpg->start.button[1],
            &rpg->window.event.mouseButton)) {
                rpg->save.is_load = true;
                rpg->start.button[1].state = RELEASED;
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->start.button[1].is_hover(rpg, &rpg->start.button[1],
            &rpg->window.event.mouseMove);
    }
}

void start_new_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->start.button[0].is_clicked(rpg, &rpg->start.button[0],
            &rpg->window.event.mouseButton)) {
                scene.scene = "char_creator";
                rpg->start.button[0].state = RELEASED;
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->start.button[0].is_hover(rpg, &rpg->start.button[0],
            &rpg->window.event.mouseMove);
    }
}

void start_quit_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->start.button[4].is_clicked(rpg, &rpg->start.button[4],
            &rpg->window.event.mouseButton)) {
                sfRenderWindow_close(rpg->window.window);
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->start.button[4].is_hover(rpg, &rpg->start.button[4],
            &rpg->window.event.mouseMove);
    }
}

void start_settings_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->start.button[2].is_clicked(rpg, &rpg->start.button[2],
            &rpg->window.event.mouseButton)) {
                rpg->settings.is_setting = true;
                rpg->start.button[2].state = RELEASED;
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->start.button[2].is_hover(rpg, &rpg->start.button[2],
            &rpg->window.event.mouseMove);
    }
}

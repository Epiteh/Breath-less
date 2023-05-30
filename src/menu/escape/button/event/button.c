/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** button
*/

#include "rpg.h"
#include <stdio.h>

void escape_credits_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->menu.button[3].is_clicked(rpg, &rpg->menu.button[3],
            &rpg->window.event.mouseButton)) {
                printf("Hello World\n");
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->menu.button[3].is_hover(rpg, &rpg->menu.button[3],
            &rpg->window.event.mouseMove);
    }
}

void escape_load_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->menu.button[1].is_clicked(rpg, &rpg->menu.button[1],
            &rpg->window.event.mouseButton)) {
                rpg->save.is_save = true;
                rpg->menu.button[1].state = RELEASED;
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->menu.button[1].is_hover(rpg, &rpg->menu.button[1],
            &rpg->window.event.mouseMove);
    }
}

void escape_quit_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->menu.button[4].is_clicked(rpg, &rpg->menu.button[4],
            &rpg->window.event.mouseButton)) {
                scene.scene = "start";
                rpg->menu.escape_menu = false;
                init_advancement(rpg);
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->menu.button[4].is_hover(rpg, &rpg->menu.button[4],
            &rpg->window.event.mouseMove);
    }
}

void escape_resume_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->menu.button[0].is_clicked(rpg, &rpg->menu.button[0],
            &rpg->window.event.mouseButton)) {
                rpg->menu.escape_menu = false;
                rpg->menu.button[0].state = RELEASED;
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->menu.button[0].is_hover(rpg, &rpg->menu.button[0],
            &rpg->window.event.mouseMove);
    }
}

void escape_settings_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->menu.button[2].is_clicked(rpg, &rpg->menu.button[2],
            &rpg->window.event.mouseButton)) {
                rpg->settings.is_setting = true;
                rpg->menu.button[2].state = RELEASED;
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->menu.button[2].is_hover(rpg, &rpg->menu.button[2],
            &rpg->window.event.mouseMove);
    }
}

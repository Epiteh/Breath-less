/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** save_file
*/

#include "rpg.h"

static void do_close_save_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtKeyPressed) {
        if (rpg->window.event.key.code == sfKeyEscape) {
            rpg->save.is_save = false;
        }
    }
}

static void do_close_load_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtKeyPressed) {
        if (rpg->window.event.key.code == sfKeyEscape) {
            rpg->save.is_load = false;
        }
    }
}

void save_ceo_event(rpg_t *rpg)
{
    if (rpg->save.is_load && !rpg->save.is_save) {
        enter_text_event(rpg);
        open_button_event(rpg);
        do_close_load_event(rpg);
    }
    if (rpg->save.is_save && !rpg->save.is_load) {
        enter_text_event(rpg);
        save_button_event(rpg);
        do_close_save_event(rpg);
    }
}

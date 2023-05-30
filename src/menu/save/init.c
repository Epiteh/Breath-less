/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** init
*/

#include "rpg.h"
#include <stdbool.h>

static void init_save_functions(rpg_t *rpg)
{
    init_save_background(rpg);
    enter_text_text(rpg);
    enter_text(rpg);
    init_save_button(rpg);
    init_open_button(rpg);
}

static void init_save_struct(rpg_t *rpg)
{
    rpg->save.is_save = false;
    rpg->save.is_load = false;
    rpg->save.txt =
        my_calloc(3, sizeof(struct save_txt));
    rpg->save.sprite =
        my_calloc(1, sizeof(struct save_sprite));
    rpg->save.button =
        my_calloc(2, sizeof(struct my_button));
}

void init_save_values(rpg_t *rpg)
{
    init_save_struct(rpg);
    init_save_functions(rpg);
}

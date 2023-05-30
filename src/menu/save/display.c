/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** display
*/

#include "rpg.h"
#include <stdbool.h>
#include <stdio.h>

void display_save_menu(rpg_t *rpg)
{
    if (rpg->save.is_load) {
        display_save_background(rpg);
        display_save_txt(rpg);
        open_button_view(rpg);
    }
    if (rpg->save.is_save) {
        display_save_background(rpg);
        display_save_txt(rpg);
        save_button_view(rpg);
    }
}

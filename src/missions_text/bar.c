/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** bar.c
*/

#include "rpg.h"
#include <stdlib.h>
#include <stdio.h>


void display_bar_mission_text(rpg_t *rpg)
{
    char *mission_message = "Find a way to get out of the bar.";

    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->mission_text.small_sprite, NULL);
    if (rpg->mission_text.is_writing == false) {
        sfRenderWindow_drawText(rpg->window.window,
            rpg->mission_text.text, NULL);
        return;
    }
    rpg->mission_text.is_writing = draw_mission_text(rpg, mission_message,
        rpg->mission_text.text, &rpg->mission_text.letter_counter);
}

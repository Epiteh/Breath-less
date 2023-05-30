/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** display.c
*/
#include "rpg.h"

void display_game_collectibles(rpg_t *rpg)
{
    manage_map_collectibles(rpg);
    manage_main_place_npc(rpg);
    if (rpg->mission.do_control_fight_done) {
        manage_back_safe_place_npc(rpg);
        rpg->mission.go_back_safe_place = true;
    }
}

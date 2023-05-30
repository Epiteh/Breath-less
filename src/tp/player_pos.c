/*
** EPITECH PROJECT, 2023
** DownLoad_RPG.donin
** File description:
** player_pos.c
*/
#include "rpg.h"

void init_tp_player(rpg_t *rpg, float x, float y)
{
    rpg->tp.player_pos.x = x;
    rpg->tp.player_pos.y = y;
}

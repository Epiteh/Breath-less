/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** enemy
*/

#include "rpg.h"

void enemy_validation(struct fight_s *fights)
{
    if (PLCHOICE == 1 && PLACTUAL != 2 && PLACTUAL != 3 && !fights->pressed) {
        fights->pressed = sfTrue;
        fights->player.datas.damage =
            fights->player.datas.attacks[PLACTUAL].damage;
        PLCHOICE = 3;
        PLACTUAL = 0;
    }
}

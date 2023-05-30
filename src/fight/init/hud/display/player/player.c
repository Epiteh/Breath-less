/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** player
*/

#include "rpg.h"

void check_player_datas(struct fight_s *fights, int idx)
{
    if (fights->place.fight) {
        if (idx == 0)
            plcheck_life(fights, idx);
        if (idx == 2)
            plcheck_mind(fights, idx);
    }
    if (fights->control.fight) {
        if (idx == 0)
            cocheck_life(fights, idx);
        if (idx == 2)
            cocheck_mind(fights, idx);
    }
}

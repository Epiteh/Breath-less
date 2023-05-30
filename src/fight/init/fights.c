/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** fights
*/

#include "rpg.h"

void init_fights(struct fight_s *fights)
{
    fights->is_attacking = 0;
    init_player(fights);
    init_place(fights);
    init_control(fights);
}

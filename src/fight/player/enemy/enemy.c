/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** enemy
*/

#include "rpg.h"
#include <stdlib.h>
#include <stdio.h>

void enemies_event(struct fight_s *fights)
{
    if (fights->place.fight) {
        place_enemies_event(fights);
    }
    if (fights->control.fight) {
        control_boss_event(fights);
    }
}

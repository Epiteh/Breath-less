/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** ceo
*/

#include "rpg.h"

static void init_place_choices(struct fight_s *fights)
{
    fights->place.choices = my_calloc(5, sizeof(*fights->place.choices));
    PLCHOICE = 0;
    init_plfirsts(fights);
    init_plattacks(fights);
    init_plinventories(fights);
    init_plenemies(fights);
    init_plenemies_turn(fights);
}

static void init_control_choices(struct fight_s *fights)
{
    fights->control.choices = my_calloc(5, sizeof(*fights->control.choices));
    fights->control.choice = 0;
    init_cofirsts(fights);
    init_coattacks(fights);
    init_coinventories(fights);
    init_coenemy(fights);
    init_coenemy_turn(fights);
}

void init_choices(struct fight_s *fights)
{
    init_place_choices(fights);
    init_control_choices(fights);
}

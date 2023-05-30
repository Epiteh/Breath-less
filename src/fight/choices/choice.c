/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** choice
*/

#include "rpg.h"

void handle_bosschoice(struct fight_s *fights)
{
    fights->is_attacking = 0;
    fights->pressed = sfFalse;

    first_bosschoice(fights);
    attack_bosschoice(fights);
    inventory_bosschoice(fights);
    enemy_bosschoice(fights);
    validation_ceo(fights);
}

void handle_choice(struct fight_s *fights)
{
    fights->is_attacking = 0;
    fights->pressed = sfFalse;

    first_choice(fights);
    attack_choice(fights);
    inventory_choice(fights);
    enemy_choice(fights);
    validation_ceo(fights);
}

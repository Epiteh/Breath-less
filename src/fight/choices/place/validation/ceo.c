/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** ceo
*/

#include "rpg.h"

static void place_vld(struct fight_s *fights)
{
    if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
        first_validation(fights);
        attack_validation(fights);
        attack_back(fights);
        inventory_validation(fights);
        inventory_back(fights);
        enemy_validation(fights);
        enemy_back(fights);
    }
}

static void control_vld(struct fight_s *fights)
{
    if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
        first_boss_vld(fights);
        attack_boss_vld(fights);
        attack_bossback(fights);
        inventory_boss_vld(fights);
        inventory_bossback(fights);
        boss_validation(fights);
        boss_back(fights);
    }
}

void validation_ceo(struct fight_s *fights)
{
    if (fights->place.fight) {
        place_vld(fights);
    }
    if (fights->control.fight) {
        control_vld(fights);
    }
}

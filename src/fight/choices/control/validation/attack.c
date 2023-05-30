/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** attack
*/

#include "rpg.h"

void attack_boss_vld(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (COCHOICE == 3 && COACTUAL == 0 && !fights->pressed) {
        fights->pressed = sfTrue;
        fights->to_attack = COACTUAL;
        COCHOICE = 0;
        COACTUAL = 3;
        fights->player_turn = false;
        fights->attacked = true;
        tmp2 = fights->control.choices[COCHOICE].position[COACTUAL - 3];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
        sfClock_restart(fights->control.clock);
    }
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** attack
*/

#include "rpg.h"

void attack_validation(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (PLCHOICE == 3 && PLACTUAL != 0 && PLACTUAL != 4 && !fights->pressed) {
        fights->pressed = sfTrue;
        fights->to_attack = PLACTUAL - 1;
        PLCHOICE = 0;
        PLACTUAL = 3;
        fights->player_turn = false;
        fights->attacked = true;
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL - 3];
        sfSprite_setPosition(fights->place.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
        sfClock_restart(fights->place.clock);
    }
}

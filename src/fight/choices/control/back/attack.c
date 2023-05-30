/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** attack
*/

#include "rpg.h"

void attack_bossback(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (COCHOICE == 1 && COACTUAL == 3 && !fights->pressed) {
        fights->pressed = sfTrue;
        COCHOICE = 0;
        COACTUAL = 3;
        tmp2 = fights->control.choices[COCHOICE].position[COACTUAL - 3];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

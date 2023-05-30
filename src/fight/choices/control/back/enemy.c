/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** enemy
*/

#include "rpg.h"

void boss_back(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (COCHOICE == 3 && COACTUAL == 1
        && !fights->pressed) {
        fights->pressed = sfTrue;
        COCHOICE = 1;
        COACTUAL = 4;
        tmp2 = fights->control.choices[COCHOICE].position[COACTUAL- 3];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

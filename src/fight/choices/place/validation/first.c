/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** first
*/

#include "rpg.h"

void first_validation(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (PLCHOICE == 0 && PLACTUAL == 0 && !fights->pressed) {
        fights->pressed = sfTrue;
        PLCHOICE = 1;
        PLACTUAL = 3;
    }
    if (PLCHOICE == 0 && PLACTUAL == 1 && !fights->pressed) {
        fights->pressed = sfTrue;
        PLCHOICE = 2;
        PLACTUAL = 3;
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL - 3];
        sfSprite_setPosition(fights->place.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

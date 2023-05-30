/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** attack
*/

#include "rpg.h"

void attack_back(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (PLCHOICE == 1 && PLACTUAL == 2 && !fights->pressed) {
        fights->pressed = sfTrue;
        PLCHOICE = 0;
        fights->place.choices[0].actual = 3;
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL - 3];
        sfSprite_setPosition(fights->place.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

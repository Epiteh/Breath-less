/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** enemy
*/

#include "rpg.h"

void enemy_back(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (PLCHOICE == 3 && PLACTUAL == 4 && !fights->pressed) {
        fights->pressed = sfTrue;
        PLCHOICE = 1;
        PLACTUAL = 3;
        tmp2 = fights->place.choices[PLACTUAL].position[PLACTUAL - 3];
        sfSprite_setPosition(fights->place.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** enemy
*/

#include "rpg.h"

static void change_from_boss(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyLeft) && COACTUAL == 0 && COCHOICE == 3
        && !fights->pressed) {
        fights->pressed = sfTrue;
        COACTUAL = 1;
        tmp2 = fights->control.choices[COCHOICE].position[COACTUAL];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x - 52, tmp2.y - 10});
    }
}

void enemy_bosschoice(struct fight_s *fights)
{
    change_from_boss(fights);
    change_from_back(fights, COCHOICE);
}

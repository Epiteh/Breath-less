/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** first_change
*/

#include "rpg.h"

void change_from_first2(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyLeft) && PLACTUAL == 1 && PLCHOICE == 3
            && !fights->pressed) {
        fights->pressed = sfTrue;
        PLACTUAL = 4;
        sfSprite_setRotation(fights->place.choices[0].arrow, 0);
        tmp2 = fights->place.choices[1].position[2];
        sfSprite_setPosition(fights->place.choices[0].arrow, (sfVector2f)
            {tmp2.x -52, tmp2.y - 10});
    }
}

void change_from_mid2(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyRight) && PLACTUAL == 2 && PLCHOICE == 3
            && !fights->pressed) {
        fights->pressed = sfTrue;
        PLACTUAL = 3;
        if (fights->place.enemies[2].datas.dead)
            return;
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL];
        sfSprite_setPosition(fights->place.choices[0].arrow, tmp2);
    }
}

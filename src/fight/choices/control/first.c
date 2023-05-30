/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** first
*/

#include "rpg.h"

static void change_from_first(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyRight) && COACTUAL == 0 && COCHOICE == 0
        && !fights->pressed) {
        fights->pressed = sfTrue;
        COACTUAL = 1;
        tmp2 = fights->control.choices[COCHOICE].position[COACTUAL];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

static void change_from_last(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyLeft) && COACTUAL == 1 && COCHOICE == 0
        && !fights->pressed) {
        fights->pressed = sfTrue;
        COACTUAL = 0;
        tmp2 = fights->control.choices[COCHOICE].position[COACTUAL];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

void first_bosschoice(struct fight_s *fights)
{
    change_from_first(fights);
    change_from_last(fights);
}

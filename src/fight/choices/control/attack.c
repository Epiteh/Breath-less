/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** attack
*/

#include "rpg.h"
#include <stdio.h>

static void change_from_first(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (COACTUAL == 0 && COCHOICE == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyRight) && !fights->pressed) {
            fights->pressed = sfTrue;
            COACTUAL = 1;
            tmp2 = fights->control.choices[COCHOICE].position[COACTUAL];
            sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
                {tmp2.x - 65, tmp2.y - 8});
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft) && !fights->pressed) {
            fights->pressed = sfTrue;
            COACTUAL = 3;
            tmp2 = fights->control.choices[COCHOICE].position[COACTUAL];
            sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
                {tmp2.x - 52, tmp2.y - 10});
        }
    }
}

static void change_from_mid(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyLeft) && COACTUAL == 1 && COCHOICE == 1
            && !fights->pressed) {
        fights->pressed = sfTrue;
        COACTUAL = 0;
        tmp2 = fights->control.choices[COCHOICE].position[COACTUAL];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 9});
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && COACTUAL == 1 && COCHOICE == 1
            && !fights->pressed) {
        fights->pressed = sfTrue;
        COACTUAL = 2;
        tmp2 = fights->control.choices[COCHOICE].position[COACTUAL];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

static void change_from_last(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyLeft) && COACTUAL == 2 && COCHOICE == 1
            && !fights->pressed) {
        fights->pressed = sfTrue;
        COACTUAL = 1;
        tmp2 = fights->control.choices[COCHOICE].position[COACTUAL];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 9});
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && COACTUAL == 3 && COCHOICE == 1
            && !fights->pressed) {
        fights->pressed = sfTrue;
        COACTUAL = 0;
        tmp2 = fights->control.choices[COCHOICE].position[COACTUAL];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 9});
    }
}

void attack_bosschoice(struct fight_s *fights)
{
    change_from_first(fights);
    change_from_mid(fights);
    change_from_last(fights);
}

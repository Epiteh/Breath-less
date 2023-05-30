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

    if (sfKeyboard_isKeyPressed(sfKeyRight) && PLACTUAL == 0 && PLCHOICE == 0
            && !fights->pressed) {
        fights->pressed = sfTrue;
        PLACTUAL = 1;
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL];
        sfSprite_setPosition(fights->place.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

static void change_from_last(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyLeft) && PLACTUAL == 1 && PLCHOICE == 0
            && !fights->pressed) {
        fights->pressed = sfTrue;
        PLACTUAL = 0;
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL];
        sfSprite_setPosition(fights->place.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

void first_choice(struct fight_s *fights)
{
    change_from_first(fights);
    change_from_last(fights);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** back_choice
*/

#include "rpg.h"

static void place_back(struct fight_s *fights, int tmp, sfVector2f tmp2)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)
        && fights->place.choices[tmp].actual == 4 && PLCHOICE == 3
            && !fights->pressed) {
        fights->pressed = sfTrue;
        PLACTUAL = 1;
        if (fights->place.enemies[0].datas.dead)
            PLACTUAL = 2;
        if (fights->place.enemies[1].datas.dead)
            PLACTUAL = 3;
        tmp2 = fights->place.choices[tmp].position[
            fights->place.choices[tmp].actual];
        sfSprite_setPosition(fights->place.choices[0].arrow, tmp2);
    }
}

static void control_back(struct fight_s *fights, int tmp, sfVector2f tmp2)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)
        && fights->control.choices[tmp].actual == 1 && PLCHOICE == 3
            && !fights->pressed) {
        fights->pressed = sfTrue;
        PLACTUAL = 0;
        tmp2 = fights->control.choices[tmp].position[
            fights->control.choices[tmp].actual];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x + 82, tmp2.y - 45});
    }
}

void change_from_back(struct fight_s *fights, int tmp)
{
    sfVector2f tmp2 = {0, 0};

    if (fights->place.fight) {
        place_back(fights, tmp, tmp2);
    }
    if (fights->control.fight) {
        control_back(fights, tmp, tmp2);
    }
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** enemy
*/

#include "rpg.h"

static void change_from_first(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyRight) && PLACTUAL == 1 && PLCHOICE == 3
            && !fights->pressed) {
        fights->pressed = sfTrue;
        PLACTUAL = 2;
        if (fights->place.enemies[1].datas.dead)
            PLACTUAL = 3;
        if (fights->place.enemies[1].datas.dead
            && fights->place.enemies[2].datas.dead)
            return;
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL];
        sfSprite_setPosition(fights->place.choices[0].arrow, tmp2);
    }
}

static void change_from_mid(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyLeft) && PLACTUAL == 2 && PLCHOICE == 3
            && !fights->pressed) {
        fights->pressed = sfTrue;
        PLACTUAL = 1;
        if (fights->place.enemies[0].datas.dead) {
            PLACTUAL = 4;
            sfSprite_setRotation(fights->place.choices[0].arrow, 0);
            tmp2 = fights->place.choices[1].position[2];
            sfSprite_setPosition(fights->place.choices[0].arrow, (sfVector2f)
                {tmp2.x -52, tmp2.y - 10});
            return;
        }
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL];
        sfSprite_setPosition(fights->place.choices[0].arrow, tmp2);
    }
}

static int last_special_cases(struct fight_s *fights, sfVector2f tmp2)
{
    if (fights->place.enemies[1].datas.dead)
        PLACTUAL = 1;
    if (fights->place.enemies[0].datas.dead
        && fights->place.enemies[1].datas.dead) {
        PLACTUAL = 4;
        sfSprite_setRotation(fights->place.choices[0].arrow, 0);
        tmp2 = fights->place.choices[1].position[2];
        sfSprite_setPosition(fights->place.choices[0].arrow, (sfVector2f)
            {tmp2.x -52, tmp2.y - 10});
        return (1);
    }
    return (0);
}

static void change_from_last(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyLeft) && PLACTUAL == 3 && PLCHOICE == 3
            && !fights->pressed) {
        fights->pressed = sfTrue;
        PLACTUAL = 2;
        if (last_special_cases(fights, tmp2) == 1)
            return;
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL];
        sfSprite_setPosition(fights->place.choices[0].arrow, tmp2);
    }
}

void enemy_choice(struct fight_s *fights)
{
    change_from_first(fights);
    change_from_first2(fights);
    change_from_mid(fights);
    change_from_mid2(fights);
    change_from_last(fights);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** attack
*/

#include "rpg.h"

static void positions(struct fight_s *fights)
{
    fights->control.choices[1].position =
        my_calloc(4, sizeof(*fights->control.choices[1].position));
    fights->control.choices[1].position[0] = (sfVector2f){400, 848};
    fights->control.choices[1].position[1] = (sfVector2f){880, 848};
    fights->control.choices[1].position[2] = (sfVector2f){1200, 848};
    fights->control.choices[1].position[3] = (sfVector2f){250, 780};
}

static void text_cases(struct fight_s *fights, int i)
{
    if (i == 0)
        sfText_setString(fights->control.choices[1].text[i],
            "Crossed Slash Combo");
    if (i == 1)
        sfText_setString(fights->control.choices[1].text[i],
            "Woke Blade");
    if (i == 2)
        sfText_setString(fights->control.choices[1].text[i],
            "Awakened Thinking");
    if (i == 3)
        sfText_setString(fights->control.choices[1].text[i],
            "Back");
}

static void texts(struct fight_s *fights)
{
    fights->control.choices[1].text =
        my_calloc(4, sizeof(*fights->control.choices[1].text));
    for (unsigned int i = 0; i < 4; i++) {
        fights->control.choices[1].text[i] = sfText_create();
        text_cases(fights, i);
        sfText_setFont(fights->control.choices[1].text[i],
            fights->control.choices[0].font);
        sfText_setCharacterSize(fights->control.choices[1].text[i], 37);
        sfText_setPosition(fights->control.choices[1].text[i],
            fights->control.choices[1].position[i]);
    }
}

void init_coattacks(struct fight_s *fights)
{
    fights->control.choices[1].actual = 0;
    positions(fights);
    texts(fights);
}

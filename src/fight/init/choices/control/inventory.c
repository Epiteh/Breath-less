/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** inventory
*/

#include "rpg.h"

static void positions(struct fight_s *fights)
{
    fights->control.choices[2].position =
        my_calloc(3, sizeof(*fights->control.choices[2].position));
    fights->control.choices[2].position[0] = (sfVector2f){550, 840};
    fights->control.choices[2].position[1] = (sfVector2f){1200, 840};
    fights->control.choices[2].position[2] = (sfVector2f){250, 780};
}

static void texts(struct fight_s *fights)
{
    fights->control.choices[2].text =
        my_calloc(3, sizeof(*fights->control.choices[2].text));
    for (unsigned int i = 0; i < 3; i++) {
        fights->control.choices[2].text[i] = sfText_create();
        if (i == 0)
            sfText_setString(fights->control.choices[2].text[i],
                "Stimulant");
        if (i == 1)
            sfText_setString(fights->control.choices[2].text[i],
                "Medikit");
        if (i == 2)
            sfText_setString(fights->control.choices[2].text[i],
                "Back");
        sfText_setFont(fights->control.choices[2].text[i],
            fights->control.choices[0].font);
        sfText_setCharacterSize(fights->control.choices[2].text[i], 40);
        sfText_setPosition(fights->control.choices[2].text[i],
            fights->control.choices[2].position[i]);
    }
}

void init_coinventories(struct fight_s *fights)
{
    fights->control.choices[2].actual = 0;
    positions(fights);
    texts(fights);
}

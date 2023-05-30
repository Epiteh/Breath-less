/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** enemy
*/

#include "rpg.h"

static void positions(struct fight_s *fights)
{
    fights->control.choices[3].position =
        my_calloc(3, sizeof(*fights->control.choices[3].position));
    fights->control.choices[3].position[0] = (sfVector2f){1250, 105};
    fights->control.choices[3].position[1] = (sfVector2f){250, 780};
    fights->control.choices[3].position[2] = (sfVector2f){700, 840};
}

static void texts(struct fight_s *fights)
{
    fights->control.choices[3].text =
        my_calloc(2, sizeof(*fights->control.choices[3].text));
    fights->control.choices[3].text[0] = sfText_create();
    sfText_setString(fights->control.choices[3].text[0],
        "Choose an enemy to attack");
    sfText_setFont(fights->control.choices[3].text[0],
        fights->control.choices[0].font);
    sfText_setCharacterSize(fights->control.choices[3].text[0], 40);
    sfText_setPosition(fights->control.choices[3].text[0],
        fights->control.choices[3].position[2]);
    fights->control.choices[3].text[1] = sfText_create();
    sfText_setString(fights->control.choices[3].text[1], "Back");
    sfText_setFont(fights->control.choices[3].text[1],
        fights->control.choices[0].font);
    sfText_setCharacterSize(fights->control.choices[3].text[1], 37);
    sfText_setPosition(fights->control.choices[3].text[1],
        fights->control.choices[3].position[1]);
}

void init_coenemy(struct fight_s *fights)
{
    fights->control.choices[3].actual = 0;
    positions(fights);
    texts(fights);
}

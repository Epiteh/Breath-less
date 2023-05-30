/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** attack
*/

#include "rpg.h"

static void positions(struct fight_s *fights)
{
    fights->place.choices[1].position =
        my_calloc(3, sizeof(*fights->place.choices[1].position));
    fights->place.choices[1].position[0] = (sfVector2f){550, 840};
    fights->place.choices[1].position[1] = (sfVector2f){1200, 840};
    fights->place.choices[1].position[2] = (sfVector2f){250, 780};
}

static void texts(struct fight_s *fights)
{
    fights->place.choices[1].text =
        my_calloc(3, sizeof(*fights->place.choices[1].text));
    for (unsigned int i = 0; i < 3; i++) {
        fights->place.choices[1].text[i] = sfText_create();
        if (i == 0)
            sfText_setString(fights->place.choices[1].text[i], "Slash");
        if (i == 1)
            sfText_setString(fights->place.choices[1].text[i],
                "Cross Stomp");
        if (i == 2)
            sfText_setString(fights->place.choices[1].text[i],
                "Back");
        sfText_setFont(fights->place.choices[1].text[i],
            fights->place.choices[0].font);
        sfText_setCharacterSize(fights->place.choices[1].text[i], 40);
        sfText_setPosition(fights->place.choices[1].text[i],
            fights->place.choices[1].position[i]);
    }
}

void init_plattacks(struct fight_s *fights)
{
    fights->place.choices[1].actual = 0;
    positions(fights);
    texts(fights);
}

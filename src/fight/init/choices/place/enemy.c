/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** enemy
*/

#include "rpg.h"

static void positions(struct fight_s *fights)
{
    fights->place.choices[3].position =
        my_calloc(5, sizeof(*fights->place.choices[3].position));
    fights->place.choices[3].position[0] = (sfVector2f){680, 840};
    fights->place.choices[3].position[1] =
        (sfVector2f){fights->place.enm_pos[0].x + 100,
            fights->place.enm_pos[0].y - 40};
    fights->place.choices[3].position[2] =
        (sfVector2f){fights->place.enm_pos[1].x + 100,
            fights->place.enm_pos[1].y - 40};
    fights->place.choices[3].position[3] =
        (sfVector2f){fights->place.enm_pos[2].x + 100,
            fights->place.enm_pos[2].y - 40};
    fights->place.choices[3].position[4] = (sfVector2f){250, 780};
}

static void texts(struct fight_s *fights)
{
    fights->place.choices[3].text =
        my_calloc(2, sizeof(*fights->place.choices[3].text));
    fights->place.choices[3].text[0] = sfText_create();
    sfText_setString(fights->place.choices[3].text[0],
        "Choose an enemy to attack");
    sfText_setFont(fights->place.choices[3].text[0],
        fights->place.choices[0].font);
    sfText_setCharacterSize(fights->place.choices[3].text[0], 40);
    sfText_setPosition(fights->place.choices[3].text[0],
        fights->place.choices[3].position[0]);
    fights->place.choices[3].text[1] = sfText_create();
    sfText_setString(fights->place.choices[3].text[1], "Back");
    sfText_setFont(fights->place.choices[3].text[1],
        fights->place.choices[0].font);
    sfText_setCharacterSize(fights->place.choices[3].text[1], 40);
    sfText_setPosition(fights->place.choices[3].text[1],
        fights->place.choices[3].position[4]);
}

void init_plenemies(struct fight_s *fights)
{
    fights->place.choices[3].actual = 0;
    positions(fights);
    texts(fights);
}

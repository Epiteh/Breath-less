/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** enemy_turn
*/

#include "rpg.h"

static void positions(struct fight_s *fights)
{
    fights->place.choices[4].position =
        my_calloc(1, sizeof(*fights->place.choices[4].position));
    fights->place.choices[4].position[0] = (sfVector2f){730, 840};
}

static void texts(struct fight_s *fights)
{
    fights->place.choices[4].text =
        my_calloc(1, sizeof(*fights->place.choices[4].text));
    fights->place.choices[4].text[0] = sfText_create();
    sfText_setString(fights->place.choices[4].text[0],
        "Enemies are attacking");
    sfText_setFont(fights->place.choices[4].text[0],
        fights->place.choices[0].font);
    sfText_setCharacterSize(fights->place.choices[4].text[0], 40);
    sfText_setPosition(fights->place.choices[4].text[0],
        fights->place.choices[4].position[0]);
}

void init_plenemies_turn(struct fight_s *fights)
{
    fights->place.choices[4].actual = 0;
    positions(fights);
    texts(fights);
}

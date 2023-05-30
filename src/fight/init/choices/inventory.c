/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** inventory
*/

#include "rpg.h"

static void positions(struct fight_s *fights)
{
    fights->choices[fights->choice].position =
        my_calloc(3, sizeof(*fights->choices[fights->choice].position));
    fights->choices[fights->choice].position[0] = (sfVector2f){550, 840};
    fights->choices[fights->choice].position[1] = (sfVector2f){1200, 840};
    fights->choices[fights->choice].position[2] = (sfVector2f){250, 780};
}

static void texts(struct fight_s *fights)
{
    fights->choices[fights->choice].text =
        my_calloc(3, sizeof(*fights->choices[fights->choice].text));
    for (unsigned int i = 0; i < 3; i++) {
        fights->choices[fights->choice].text[i] = sfText_create();
        if (i == 0)
            sfText_setString(fights->choices[fights->choice].text[i],
                "Stimulant");
        if (i == 1)
            sfText_setString(fights->choices[fights->choice].text[i],
                "Medikit");
        if (i == 2)
            sfText_setString(fights->choices[fights->choice].text[i],
                "Back");
        sfText_setFont(fights->choices[fights->choice].text[i],
            fights->choices[0].font);
        sfText_setCharacterSize(fights->choices[fights->choice].text[i], 40);
        sfText_setPosition(fights->choices[fights->choice].text[i],
            fights->choices[fights->choice].position[i]);
    }
}

void init_inventories(struct fight_s *fights)
{
    fights->choices[fights->choice].actual = 0;
    positions(fights);
    texts(fights);
}

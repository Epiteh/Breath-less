/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** first
*/

#include "rpg.h"

static void arrow(struct fight_s *fights)
{
    fights->place.choices[0].arrow = sfSprite_create();
    fights->place.choices[0].arrow_texture =
        sfTexture_createFromFile("assets/arrow.png", NULL);
    sfSprite_setTexture(fights->place.choices[0].arrow,
        fights->place.choices[0].arrow_texture, sfTrue);
    sfSprite_setPosition(fights->place.choices[0].arrow,
        (sfVector2f){485, 832});
    sfSprite_setScale(fights->place.choices[0].arrow,
        (sfVector2f){2.2, 2.2});
}

static void positions(struct fight_s *fights)
{
    fights->place.choices[0].position =
        my_calloc(2,
            sizeof(*fights->place.choices[0].position));
    fights->place.choices[0].position[0] = (sfVector2f){550, 840};
    fights->place.choices[0].position[1] = (sfVector2f){1200, 840};
}

static void texts(struct fight_s *fights)
{
    fights->place.choices[0].font =
        sfFont_createFromFile("assets/Roboto-Light.ttf");
    fights->place.choices[0].text =
        my_calloc(2, sizeof(*fights->place.choices[0].text));
    fights->place.choices[0].text[0] = sfText_create();
    sfText_setString(fights->place.choices[0].text[0], "Attack");
    sfText_setFont(fights->place.choices[0].text[0],
        fights->place.choices[0].font);
    sfText_setCharacterSize(fights->place.choices[0].text[0], 40);
    sfText_setPosition(fights->place.choices[0].text[0],
        fights->place.choices[0].position[0]);
    fights->place.choices[0].text[1] = sfText_create();
    sfText_setString(fights->place.choices[0].text[1], "Inventory");
    sfText_setFont(fights->place.choices[0].text[1],
        fights->place.choices[0].font);
    sfText_setCharacterSize(fights->place.choices[0].text[1], 40);
    sfText_setPosition(fights->place.choices[0].text[1],
        fights->place.choices[0].position[1]);
}

void init_plfirsts(struct fight_s *fights)
{
    fights->place.choices[0].actual = 0;
    arrow(fights);
    positions(fights);
    texts(fights);
}

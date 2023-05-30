/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** first
*/

#include "rpg.h"

static void arrow(struct fight_s *fights)
{
    fights->control.choices[0].arrow = sfSprite_create();
    fights->control.choices[0].arrow_texture =
        sfTexture_createFromFile("assets/arrow.png", NULL);
    sfSprite_setTexture(fights->control.choices[0].arrow,
        fights->control.choices[0].arrow_texture, sfTrue);
    sfSprite_setPosition(fights->control.choices[0].arrow,
        (sfVector2f){485, 832});
    sfSprite_setScale(fights->control.choices[0].arrow,
        (sfVector2f){2.2, 2.2});
}

static void positions(struct fight_s *fights)
{
    fights->control.choices[0].position =
        my_calloc(2,
            sizeof(*fights->control.choices[0].position));
    fights->control.choices[0].position[0] = (sfVector2f){550, 840};
    fights->control.choices[0].position[1] = (sfVector2f){1200, 840};
}

static void texts(struct fight_s *fights)
{
    fights->control.choices[0].font =
        sfFont_createFromFile("assets/Roboto-Light.ttf");
    fights->control.choices[0].text =
        my_calloc(2, sizeof(*fights->control.choices[0].text));
    fights->control.choices[0].text[0] = sfText_create();
    sfText_setString(fights->control.choices[0].text[0], "Attack");
    sfText_setFont(fights->control.choices[0].text[0],
        fights->control.choices[0].font);
    sfText_setCharacterSize(fights->control.choices[0].text[0], 40);
    sfText_setPosition(fights->control.choices[0].text[0],
        fights->control.choices[0].position[0]);
    fights->control.choices[0].text[1] = sfText_create();
    sfText_setString(fights->control.choices[0].text[1], "Inventory");
    sfText_setFont(fights->control.choices[0].text[1],
        fights->control.choices[0].font);
    sfText_setCharacterSize(fights->control.choices[0].text[1], 40);
    sfText_setPosition(fights->control.choices[0].text[1],
        fights->control.choices[0].position[1]);
}

void init_cofirsts(struct fight_s *fights)
{
    fights->control.choices[0].actual = 0;
    arrow(fights);
    positions(fights);
    texts(fights);
}

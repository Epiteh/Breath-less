/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** level
*/

#include "rpg.h"

void enemies_lvl(struct fight_s *fights, sfColor color)
{
    fights->place.hud[4].sprite = sfSprite_create();
    fights->place.hud[4].texture =
        sfTexture_createFromFile("assets/bars_states/full.png", NULL);
    sfSprite_setTexture(fights->place.hud[4].sprite,
        fights->place.hud[4].texture, sfTrue);
    sfSprite_setColor(fights->place.hud[4].sprite, color);
    sfSprite_setPosition(fights->place.hud[4].sprite, (sfVector2f){1247, 452});
    fights->place.hud[4].text = sfText_create();
    sfText_setString(fights->place.hud[4].text, "Lvl. 3");
    sfText_setFont(fights->place.hud[4].text, fights->place.choices[0].font);
    sfText_setCharacterSize(fights->place.hud[4].text, 18);
    sfText_setColor(fights->place.hud[4].text, sfBlack);
    sfText_setPosition(fights->place.hud[4].text, (sfVector2f){1322, 451});
}

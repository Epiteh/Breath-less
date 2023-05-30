/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** level
*/

#include "rpg.h"

static void place_lvl(struct fight_s *fights, sfColor color)
{
    fights->place.hud[3].sprite = sfSprite_create();
    fights->place.hud[3].texture =
        sfTexture_createFromFile("assets/bars_states/full.png", NULL);
    sfSprite_setTexture(fights->place.hud[3].sprite,
        fights->place.hud[3].texture, sfTrue);
    sfSprite_setColor(fights->place.hud[3].sprite, color);
    sfSprite_setPosition(fights->place.hud[3].sprite, (sfVector2f){490, 285});
    fights->place.hud[3].text = sfText_create();
    sfText_setString(fights->place.hud[3].text, "Lvl. 1");
    sfText_setFont(fights->place.hud[3].text, fights->place.choices[0].font);
    sfText_setCharacterSize(fights->place.hud[3].text, 18);
    sfText_setColor(fights->place.hud[3].text, sfBlack);
    sfText_setPosition(fights->place.hud[3].text, (sfVector2f){565, 284});
}

static void control_lvl(struct fight_s *fights, sfColor color)
{
    fights->control.hud[3].sprite = sfSprite_create();
    fights->control.hud[3].texture =
        sfTexture_createFromFile("assets/bars_states/full.png", NULL);
    sfSprite_setTexture(fights->control.hud[3].sprite,
        fights->control.hud[3].texture, sfTrue);
    sfSprite_setColor(fights->control.hud[3].sprite, color);
    sfSprite_setPosition(fights->control.hud[3].sprite,
        (sfVector2f){490, 285});
    fights->control.hud[3].text = sfText_create();
    sfText_setString(fights->control.hud[3].text, "Lvl. 6");
    sfText_setFont(fights->control.hud[3].text,
        fights->control.choices[0].font);
    sfText_setCharacterSize(fights->control.hud[3].text, 18);
    sfText_setColor(fights->control.hud[3].text, sfBlack);
    sfText_setPosition(fights->control.hud[3].text, (sfVector2f){565, 284});
}

void player_lvl(struct fight_s *fights, sfColor color)
{
    place_lvl(fights, color);
    control_lvl(fights, color);
}

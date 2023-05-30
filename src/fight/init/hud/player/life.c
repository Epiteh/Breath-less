/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** life
*/

#include "rpg.h"

static void place_life(struct fight_s *fights, sfColor color)
{
    fights->place.hud[0].sprite = sfSprite_create();
    fights->place.hud[0].texture =
        sfTexture_createFromFile("assets/bars_states/full.png", NULL);
    sfSprite_setTexture(fights->place.hud[0].sprite,
        fights->place.hud[0].texture, sfTrue);
    sfSprite_setColor(fights->place.hud[0].sprite, color);
    sfSprite_setPosition(fights->place.hud[0].sprite, (sfVector2f){490, 129});
    fights->place.hud[0].text = sfText_create();
    sfText_setString(fights->place.hud[0].text, "200/200");
    sfText_setFont(fights->place.hud[0].text, fights->place.choices[0].font);
    sfText_setCharacterSize(fights->place.hud[0].text, 18);
    sfText_setColor(fights->place.hud[0].text, sfBlack);
    sfText_setPosition(fights->place.hud[0].text, (sfVector2f){550, 128});
}

static void control_life(struct fight_s *fights, sfColor color)
{
    fights->control.hud[0].sprite = sfSprite_create();
    fights->control.hud[0].texture =
        sfTexture_createFromFile("assets/bars_states/full.png", NULL);
    sfSprite_setTexture(fights->control.hud[0].sprite,
        fights->control.hud[0].texture, sfTrue);
    sfSprite_setColor(fights->control.hud[0].sprite, color);
    sfSprite_setPosition(fights->control.hud[0].sprite,
        (sfVector2f){490, 129});
    fights->control.hud[0].text = sfText_create();
    sfText_setString(fights->control.hud[0].text, "850/850");
    sfText_setFont(fights->control.hud[0].text,
        fights->control.choices[0].font);
    sfText_setCharacterSize(fights->control.hud[0].text, 18);
    sfText_setColor(fights->control.hud[0].text, sfBlack);
    sfText_setPosition(fights->control.hud[0].text, (sfVector2f){550, 128});
}

void player_life(struct fight_s *fights, sfColor color)
{
    place_life(fights, color);
    control_life(fights, color);
}

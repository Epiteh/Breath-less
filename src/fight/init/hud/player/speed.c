/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** speed
*/

#include "rpg.h"

static void place_speed(struct fight_s *fights, sfColor color)
{
    fights->place.hud[1].sprite = sfSprite_create();
    fights->place.hud[1].texture =
        sfTexture_createFromFile("assets/bars_states/full.png", NULL);
    sfSprite_setTexture(fights->place.hud[1].sprite,
        fights->place.hud[1].texture, sfTrue);
    sfSprite_setColor(fights->place.hud[1].sprite, color);
    sfSprite_setPosition(fights->place.hud[1].sprite, (sfVector2f){490, 182});
    fights->place.hud[1].text = sfText_create();
    sfText_setString(fights->place.hud[1].text, "1");
    sfText_setFont(fights->place.hud[1].text, fights->place.choices[0].font);
    sfText_setCharacterSize(fights->place.hud[1].text, 18);
    sfText_setColor(fights->place.hud[1].text, sfBlack);
    sfText_setPosition(fights->place.hud[1].text, (sfVector2f){580, 181});
}

static void control_speed(struct fight_s *fights, sfColor color)
{
    fights->control.hud[1].sprite = sfSprite_create();
    fights->control.hud[1].texture =
        sfTexture_createFromFile("assets/bars_states/full.png", NULL);
    sfSprite_setTexture(fights->control.hud[1].sprite,
        fights->control.hud[1].texture, sfTrue);
    sfSprite_setColor(fights->control.hud[1].sprite, color);
    sfSprite_setPosition(fights->control.hud[1].sprite,
        (sfVector2f){490, 182});
    fights->control.hud[1].text = sfText_create();
    sfText_setString(fights->control.hud[1].text, "2");
    sfText_setFont(fights->control.hud[1].text,
        fights->control.choices[0].font);
    sfText_setCharacterSize(fights->control.hud[1].text, 18);
    sfText_setColor(fights->control.hud[1].text, sfBlack);
    sfText_setPosition(fights->control.hud[1].text, (sfVector2f){580, 181});
}

void player_speed(struct fight_s *fights, sfColor color)
{
    place_speed(fights, color);
    control_speed(fights, color);
}

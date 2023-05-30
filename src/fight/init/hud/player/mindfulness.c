/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** mindfulness
*/

#include "rpg.h"

static void place_mind(struct fight_s *fights, sfColor color)
{
    fights->place.hud[2].sprite = sfSprite_create();
    fights->place.hud[2].texture =
        sfTexture_createFromFile("assets/bars_states/full.png", NULL);
    sfSprite_setTexture(fights->place.hud[2].sprite,
        fights->place.hud[2].texture, sfTrue);
    sfSprite_setColor(fights->place.hud[2].sprite, color);
    sfSprite_setPosition(fights->place.hud[2].sprite, (sfVector2f){490, 233});
    fights->place.hud[2].text = sfText_create();
    sfText_setString(fights->place.hud[2].text, "100/100");
    sfText_setFont(fights->place.hud[2].text, fights->place.choices[0].font);
    sfText_setCharacterSize(fights->place.hud[2].text, 18);
    sfText_setColor(fights->place.hud[2].text, sfBlack);
    sfText_setPosition(fights->place.hud[2].text, (sfVector2f){550, 232});
}

static void control_mind(struct fight_s *fights, sfColor color)
{
    fights->control.hud[2].sprite = sfSprite_create();
    fights->control.hud[2].texture =
        sfTexture_createFromFile("assets/bars_states/full.png", NULL);
    sfSprite_setTexture(fights->control.hud[2].sprite,
        fights->control.hud[2].texture, sfTrue);
    sfSprite_setColor(fights->control.hud[2].sprite, color);
    sfSprite_setPosition(fights->control.hud[2].sprite,
        (sfVector2f){490, 233});
    fights->control.hud[2].text = sfText_create();
    sfText_setString(fights->control.hud[2].text, "100/100");
    sfText_setFont(fights->control.hud[2].text,
        fights->control.choices[0].font);
    sfText_setCharacterSize(fights->control.hud[2].text, 18);
    sfText_setColor(fights->control.hud[2].text, sfBlack);
    sfText_setPosition(fights->control.hud[2].text, (sfVector2f){550, 232});
}

void player_mind(struct fight_s *fights, sfColor color)
{
    place_mind(fights, color);
    control_mind(fights, color);
}

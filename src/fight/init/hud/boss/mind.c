/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** mind
*/

#include "rpg.h"

void boss_mind(struct fight_s *fights, sfColor color)
{
    fights->control.hud[6].sprite = sfSprite_create();
    fights->control.hud[6].texture =
        sfTexture_createFromFile("assets/bars_states/full.png", NULL);
    sfSprite_setTexture(fights->control.hud[6].sprite,
        fights->control.hud[6].texture, sfTrue);
    sfSprite_setColor(fights->control.hud[6].sprite, color);
    sfSprite_setPosition(fights->control.hud[6].sprite,
        (sfVector2f){1247, 552});
    fights->control.hud[6].text = sfText_create();
    sfText_setString(fights->control.hud[6].text, "-900000");
    sfText_setFont(fights->control.hud[6].text,
        fights->control.choices[0].font);
    sfText_setCharacterSize(fights->control.hud[6].text, 18);
    sfText_setColor(fights->control.hud[6].text, sfBlack);
    sfText_setPosition(fights->control.hud[6].text,
        (sfVector2f){1308, 551});
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** level
*/

#include "rpg.h"

void boss_lvl(struct fight_s *fights, sfColor color)
{
    fights->control.hud[4].sprite = sfSprite_create();
    fights->control.hud[4].texture =
        sfTexture_createFromFile("assets/bars_states/full.png", NULL);
    sfSprite_setTexture(fights->control.hud[4].sprite,
        fights->control.hud[4].texture, sfTrue);
    sfSprite_setColor(fights->control.hud[4].sprite, color);
    sfSprite_setPosition(fights->control.hud[4].sprite,
        (sfVector2f){1247, 452});
    fights->control.hud[4].text = sfText_create();
    sfText_setString(fights->control.hud[4].text, "Lvl. 99");
    sfText_setFont(fights->control.hud[4].text,
        fights->control.choices[0].font);
    sfText_setCharacterSize(fights->control.hud[4].text, 18);
    sfText_setColor(fights->control.hud[4].text, sfBlack);
    sfText_setPosition(fights->control.hud[4].text, (sfVector2f){1318, 451});
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** life
*/

#include "rpg.h"

void boss_life(struct fight_s *fights, sfColor color)
{
    fights->control.hud[5].sprite = sfSprite_create();
    fights->control.hud[5].texture =
        sfTexture_createFromFile("assets/bars_states/full.png", NULL);
    sfSprite_setTexture(fights->control.hud[5].sprite,
        fights->control.hud[5].texture, sfTrue);
    sfSprite_setColor(fights->control.hud[5].sprite, color);
    sfSprite_setPosition(fights->control.hud[5].sprite,
        (sfVector2f){1247, 502});
    fights->control.hud[5].text = sfText_create();
    sfText_setString(fights->control.hud[5].text, "850/850");
    sfText_setFont(fights->control.hud[5].text,
        fights->control.choices[0].font);
    sfText_setCharacterSize(fights->control.hud[5].text, 18);
    sfText_setColor(fights->control.hud[5].text, sfBlack);
    sfText_setPosition(fights->control.hud[5].text,
        (sfVector2f){1311, 501});
}

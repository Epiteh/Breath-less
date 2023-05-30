/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** txt
*/

#include "rpg.h"

void init_hdr_number(rpg_t *rpg)
{
    rpg->settings.txt[4].text = sfText_create();
    sfText_setString(rpg->settings.txt[4].text, "Not available");
    sfText_setFont(rpg->settings.txt[4].text, rpg->font);
    sfText_setCharacterSize(rpg->settings.txt[4].text, 37);
    sfText_setColor(rpg->settings.txt[4].text, sfBlack);
    sfText_setPosition(rpg->settings.txt[4].text,
        (sfVector2f){1125, 370});
}

void hdr_number_view(rpg_t *rpg)
{
    sfRenderWindow_drawText(rpg->window.window,
        rpg->settings.txt[4].text, NULL);
}

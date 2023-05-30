/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** number
*/

#include "rpg.h"

void init_fps_number(rpg_t *rpg)
{
    rpg->fps.str = my_calloc(10, sizeof(char));
    my_itoa(rpg->fps.fps, rpg->fps.str);

    rpg->settings.txt[0].text = sfText_create();
    sfText_setString(rpg->settings.txt[0].text, rpg->fps.str);
    sfText_setFont(rpg->settings.txt[0].text, rpg->font);
    sfText_setCharacterSize(rpg->settings.txt[0].text, 37);
    sfText_setColor(rpg->settings.txt[0].text, sfBlack);
    sfText_setPosition(rpg->settings.txt[0].text,
        (sfVector2f){1200, 242});
}

void fps_number_view(rpg_t *rpg)
{
    sfRenderWindow_drawText(rpg->window.window,
        rpg->settings.txt[0].text, NULL);
}

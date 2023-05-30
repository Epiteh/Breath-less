/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** subfuncs
*/

#include "rpg.h"

void replace_pltexture(struct fight_s *fights, int idx, char *path)
{
    sfTexture_destroy(fights->place.hud[idx].texture);
    fights->place.hud[idx].texture =
        sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(fights->place.hud[idx].sprite,
        fights->place.hud[idx].texture, sfTrue);
}

void replace_cotexture(struct fight_s *fights, int idx, char *path)
{
    sfTexture_destroy(fights->control.hud[idx].texture);
    fights->control.hud[idx].texture =
        sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(fights->control.hud[idx].sprite,
        fights->control.hud[idx].texture, sfTrue);
}

void replace_plstr(struct fight_s *fights, int tmp, int idx, char *str)
{
    my_itoa(tmp, str);
    str = my_strcat2(str, fights->tmp);
    sfText_setString(fights->place.hud[idx].text, str);
}

void replace_costr(struct fight_s *fights, int tmp, int idx, char *str)
{
    my_itoa(tmp, str);
    str = my_strcat2(str, fights->tmp);
    sfText_setString(fights->control.hud[idx].text, str);
}

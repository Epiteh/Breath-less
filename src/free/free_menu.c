/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** free_menu
*/

#include "rpg.h"

void free_menu(rpg_t *rpg)
{
    sfClock_destroy(rpg->clock.clock);
    sfSprite_destroy(rpg->start.sprite_menu[0].sprite);
    sfTexture_destroy(rpg->start.sprite_menu[0].texture);
    for (int i = 0; i < 3; i++) {
        sfText_destroy(rpg->start.txt_menu[i].text);
    }
    sfRenderWindow_close(rpg->window.window);
}

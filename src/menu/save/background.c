/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** backgroud
*/

#include "rpg.h"

void init_save_background(rpg_t *rpg)
{
    rpg->save.sprite[0].texture =
        sfTexture_createFromFile("assets/save_menu.png", NULL);
    rpg->save.sprite[0].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->save.sprite[0].sprite,
        rpg->save.sprite[0].texture, sfTrue);
}

void display_save_background(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->save.sprite[0].sprite, NULL);
}

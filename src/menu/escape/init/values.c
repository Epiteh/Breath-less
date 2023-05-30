/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** values
*/

#include "rpg.h"

static void init_escape_bg_menu(rpg_t *rpg)
{
    rpg->menu.sprite_menu[0].sprite = sfSprite_create();
    rpg->menu.sprite_menu[0].texture =
        sfTexture_createFromFile("assets/menu/escape/menu.png", NULL);
    sfSprite_setTexture(rpg->menu.sprite_menu[0].sprite,
        rpg->menu.sprite_menu[0].texture, sfTrue);
    sfSprite_setPosition(rpg->menu.sprite_menu[0].sprite,
        (sfVector2f){0, -15});
}

static void init_menu_buttons(rpg_t *rpg)
{
    init_escape_bg_menu(rpg);
    init_escape_credit(rpg);
    init_escape_load(rpg);
    init_escape_quit(rpg);
    init_escape_resume(rpg);
    init_escape_settings(rpg);
}

static void init_menu_struct(rpg_t *rpg)
{
    rpg->menu.sprite_menu = my_calloc(1, sizeof(struct sprite_menu));
    rpg->menu.button = my_calloc(5, sizeof(struct my_button));
    rpg->menu.txt_menu = my_calloc(5, sizeof(struct txt_menu));
    rpg->menu.escape_menu = false;
}

void init_escape_menu_values(rpg_t *rpg)
{
    init_menu_struct(rpg);
    init_menu_buttons(rpg);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** display
*/

#include "rpg.h"

void init_hud_background_menu(rpg_t *rpg)
{
    rpg->hud.hud_spr = sfSprite_create();
    rpg->hud.hud_txr =
        sfTexture_createFromFile("assets/hud.png", NULL);
    sfSprite_setTexture(rpg->hud.hud_spr, rpg->hud.hud_txr, sfTrue);
    sfSprite_setScale(rpg->hud.hud_spr, (sfVector2f){1.01, 0.95});
}

void display_hud_background_menu(rpg_t *rpg)
{
    if (my_strcmp(scene.scene, "start") != 0
        && my_strcmp(scene.scene, "fight") != 0
            && my_strcmp(scene.scene, "loader") != 0
                && my_strcmp(scene.scene, "boss") != 0
                    && my_strcmp(scene.scene, "char_creator") != 0) {
    sfRenderWindow_setView(rpg->window.window,
        sfRenderWindow_getDefaultView(rpg->window.window));
    sfRenderWindow_drawSprite(rpg->window.window, rpg->hud.hud_spr, NULL);
    }
}

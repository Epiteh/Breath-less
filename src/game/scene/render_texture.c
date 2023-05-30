/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** render_texture
*/

#include "rpg.h"

void display_render_texture(rpg_t *rpg)
{
    sfRenderTexture_display(rpg->background.map_render_texture);
    rpg->background.map_texture =
        sfRenderTexture_getTexture(rpg->background.map_render_texture);
    sfSprite_setTexture(rpg->background.map_sprite,
        rpg->background.map_texture, sfTrue);
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->background.map_sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->sprite.sprite, NULL);
    if (my_strcmp(scene.scene, "game") == 0) {
        sfRenderWindow_drawSprite(rpg->window.window,
            rpg->background.three_sprite, NULL);
    }
}

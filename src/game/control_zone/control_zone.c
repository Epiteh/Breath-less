/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** control_zone
*/

#include "rpg.h"

void init_control_zone_scene(rpg_t *rpg)
{
    rpg->control_zone.texture =
        sfTexture_createFromFile("assets/maps/zone_controle/control.png", NULL);
    rpg->control_zone.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->control_zone.sprite,
        rpg->control_zone.texture, sfTrue);
    rpg->control_zone.image =
        sfImage_createFromFile("assets/maps/zone_controle/controle_col.png");
    sfSprite_setPosition(rpg->control_zone.sprite,
        (sfVector2f){0, 0});
}

void display_control_zone_scene(rpg_t *rpg)
{
    scrolling(rpg);
    stop_move(rpg);
    sfView_reset(rpg->view.view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->control_zone.sprite, NULL);
    rpg->sprite.sprite_size.x = 2.7;
    rpg->sprite.sprite_size.y = 2.7;
    rpg->view.lower_x = 371 + 33 - (800 / 2);
    rpg->view.lower_y = 220 + 33 - (500 / 2);
    rpg->view.upper_x = 1007 + 33 - (800 / 2);
    rpg->view.upper_y = 436 + 33 - (500 / 2);
}

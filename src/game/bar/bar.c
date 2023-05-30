/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bar
*/

#include "rpg.h"

void init_bar_scene(rpg_t *rpg)
{
    rpg->bar.texture =
        sfTexture_createFromFile("assets/maps/bar/bar.png", NULL);
    rpg->bar.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->bar.sprite,
        rpg->bar.texture, sfTrue);
    rpg->bar.image =
        sfImage_createFromFile("assets/maps/bar/collision_bar.png");
    sfSprite_setPosition(rpg->bar.sprite,
        (sfVector2f){0, 0});
}

void display_bar_scene(rpg_t *rpg)
{
    rpg->sprite.sprite_size.x = 2.7;
    rpg->sprite.sprite_size.y = 2.7;
    rpg->view.lower_x = 0;
    rpg->view.lower_y = 0;
    rpg->view.upper_x = 710;
    rpg->view.upper_y = 795;
    scrolling(rpg);
    stop_move(rpg);
    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->bar.sprite, NULL);
}

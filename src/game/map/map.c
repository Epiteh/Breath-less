/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** map
*/

#include "rpg.h"

void display_map(rpg_t *rpg)
{
    scrolling(rpg);
    stop_move(rpg);
    sfView_reset(rpg->view.view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->sprite.sprite_bg, NULL);
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->sprite.sprite, NULL);
    rpg->sprite.sprite_size.x = 1.4;
    rpg->sprite.sprite_size.y = 1.4;
    rpg->view.lower_x = 0;
    rpg->view.lower_y = 0;
    rpg->view.upper_x = 1400;
    rpg->view.upper_y = 1695;
}

void init_map(rpg_t *rpg)
{
    rpg->sprite.texture_bg =
        sfTexture_createFromFile("assets/map/main_map.png", NULL);
    rpg->sprite.sprite_bg = sfSprite_create();
        sfSprite_setTexture(rpg->sprite.sprite_bg, rpg->sprite.texture_bg,
            sfTrue);
    rpg->sprite.image_bg =
        sfImage_createFromFile("assets/map/main_map_col.png");
    sfSprite_setPosition(rpg->sprite.sprite_bg, (sfVector2f){0, 0});

    rpg->sprite.lower_x = -13;
    rpg->sprite.lower_y = -5;
    rpg->sprite.upper_x = 2165;
    rpg->sprite.upper_y = 2153;
}

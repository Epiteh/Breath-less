/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** safe place
*/

#include "rpg.h"

void init_safe_place_scene(rpg_t *rpg)
{
    rpg->safe_place.texture =
        sfTexture_createFromFile("assets/maps/safe_place/safe.png", NULL);
    rpg->safe_place.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->safe_place.sprite,
        rpg->safe_place.texture, sfTrue);
    rpg->safe_place.image =
        sfImage_createFromFile("assets/maps/safe_place/safe_col.png");
    sfSprite_setPosition(rpg->safe_place.sprite,
        (sfVector2f){0, 0});
}

void display_safe_place_scene(rpg_t *rpg)
{
    scrolling(rpg);
    stop_move(rpg);
    sfView_reset(rpg->view.view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->safe_place.sprite, NULL);
    rpg->sprite.sprite_size.x = 2.7;
    rpg->sprite.sprite_size.y = 2.7;
    rpg->view.lower_x = 370 + 33 - (800 / 2);
    rpg->view.lower_y = 228 + 33 - (500 / 2);
    rpg->view.upper_x = 514  + 33 - (800 / 2);
    rpg->view.upper_y = 510  + 33 - (500 / 2);
}

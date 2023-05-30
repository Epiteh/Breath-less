/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** safe place
*/

#include "rpg.h"

void init_factory_scene(rpg_t *rpg)
{
    rpg->factory.texture =
        sfTexture_createFromFile("assets/maps/factory/usine.png", NULL);
    rpg->factory.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->factory.sprite,
        rpg->factory.texture, sfTrue);
    rpg->factory.image = sfImage_createFromFile(
        "assets/maps/factory/usine_col.png");
    sfSprite_setPosition(rpg->factory.sprite,
        (sfVector2f){0, 0});
}

void display_factory_scene(rpg_t *rpg)
{
    scrolling(rpg);
    stop_move(rpg);
    sfView_reset(rpg->view.view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->factory.sprite, NULL);
    rpg->sprite.sprite_size.x = 2.7;
    rpg->sprite.sprite_size.y = 2.7;
    rpg->view.lower_x = 376 + 33 - (800 / 2);;
    rpg->view.lower_y = 225 + 33 - (500 / 2);;
    rpg->view.upper_x = 939 + 33 - (800 / 2);;
    rpg->view.upper_y = 870 + 33 - (500 / 2);;
}

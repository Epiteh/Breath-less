/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** safe place
*/

#include "rpg.h"

void init_factory_basement_scene(rpg_t *rpg)
{
    rpg->factory_basement.texture =
        sfTexture_createFromFile(
            "assets/maps/factory/usine_sous-sol.png", NULL);
    rpg->factory_basement.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->factory_basement.sprite,
        rpg->factory_basement.texture, sfTrue);
    rpg->factory_basement.image =
    sfImage_createFromFile("assets/maps/factory/usine_sous-sol_col.png");
    sfSprite_setPosition(rpg->factory_basement.sprite,
        (sfVector2f){0, 0});
}

void display_factory_basement_scene(rpg_t *rpg)
{
    scrolling(rpg);
    stop_move(rpg);
    sfView_reset(rpg->view.view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->factory_basement.sprite, NULL);
    rpg->sprite.sprite_size.x = 2.7;
    rpg->sprite.sprite_size.y = 2.7;
    rpg->view.lower_x = 379 + 33 - (800 / 2);;
    rpg->view.lower_y = 224 + 33 - (500 / 2);;
    rpg->view.upper_x = 935 + 33 - (800 / 2);;
    rpg->view.upper_y = 870 + 33 - (500 / 2);;
}

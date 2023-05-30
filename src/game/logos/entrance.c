/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** safe place
*/

#include "rpg.h"

void init_logos_entrance_scene(rpg_t *rpg)
{
    rpg->logos_entrance.texture =
        sfTexture_createFromFile("assets/maps/logos/logos_entree.png", NULL);
    rpg->logos_entrance.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->logos_entrance.sprite,
        rpg->logos_entrance.texture, sfTrue);
    rpg->logos_entrance.image = sfImage_createFromFile(
        "assets/maps/logos/logos_entree_col.png");
    sfSprite_setPosition(rpg->logos_entrance.sprite,
        (sfVector2f){0, 0});
}

void display_logos_entrance_scene(rpg_t *rpg)
{
    scrolling(rpg);
    stop_move(rpg);
    sfView_reset(rpg->view.view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->logos_entrance.sprite, NULL);
    rpg->sprite.sprite_size.x = 2.7;
    rpg->sprite.sprite_size.y = 2.7;
    rpg->view.lower_x = 369 + 33 - (800 / 2);
    rpg->view.lower_y = 220 + 33 - (500 / 2);
    rpg->view.upper_x = 577 + 33 - (800 / 2);
    rpg->view.upper_y = 364 + 33 - (500 / 2);
}

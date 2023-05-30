/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** safe place
*/

#include "rpg.h"

void init_logos_office_scene(rpg_t *rpg)
{
    rpg->logos_office.texture =
        sfTexture_createFromFile("assets/maps/logos/logos_bureau.png", NULL);
    rpg->logos_office.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->logos_office.sprite,
        rpg->logos_office.texture, sfTrue);
    rpg->logos_office.image =
        sfImage_createFromFile("assets/maps/logos/logos_bureau_col.png");
    sfSprite_setPosition(rpg->logos_office.sprite,
        (sfVector2f){0, 0});
}

void display_logos_office_scene(rpg_t *rpg)
{
    scrolling(rpg);
    stop_move(rpg);
    sfView_reset(rpg->view.view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->logos_office.sprite, NULL);
    rpg->sprite.sprite_size.x = 2.7;
    rpg->sprite.sprite_size.y = 2.7;

    rpg->view.lower_x = 370 + 33 - (800 / 2);
    rpg->view.lower_y = 220 + 33 - (500 / 2);
    rpg->view.upper_x = 652 + 33 - (800 / 2);
    rpg->view.upper_y = 650 + 33 - (500 / 2);
}

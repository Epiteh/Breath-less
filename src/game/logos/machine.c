/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** safe place
*/

#include "rpg.h"

void init_logos_machine_scene(rpg_t *rpg)
{
    rpg->logos_machine.texture =
        sfTexture_createFromFile(
        "assets/maps/logos/logos_sallemachine.png", NULL);
    rpg->logos_machine.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->logos_machine.sprite,
        rpg->logos_machine.texture, sfTrue);
    rpg->logos_machine.image =
        sfImage_createFromFile("assets/maps/logos/logos_sallemachine_col.png");
    sfSprite_setPosition(rpg->logos_machine.sprite,
        (sfVector2f){0, 0});
}

void display_logos_machine_scene(rpg_t *rpg)
{
    scrolling(rpg);
    stop_move(rpg);
    sfView_reset(rpg->view.view, (sfFloatRect){0, 0, 1920, 1080});
    sfRenderTexture_drawSprite(rpg->background.map_render_texture,
        rpg->logos_machine.sprite, NULL);
    rpg->sprite.sprite_size.x = 2.7;
    rpg->sprite.sprite_size.y = 2.7;
    rpg->view.lower_x = 370 + 33 - (800 / 2);
    rpg->view.lower_y = 221 + 33 - (500 / 2);
    rpg->view.upper_x = 434 + 33 - (800 / 2);
    rpg->view.upper_y = 645 + 33 - (500 / 2);
}

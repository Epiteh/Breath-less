/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** display
*/

#include "rpg.h"

static void free_loader(rpg_t *rpg)
{
    for (int i = 0; i < 1; i++) {
        sfRectangleShape_destroy(rpg->loader.rect[i].rect);
        sfSprite_destroy(rpg->loader.sprite[i].sprite);
    }
    sfClock_destroy(rpg->loader.clock.clock);
}

static void change_loader_scene(rpg_t *rpg)
{
    float time =
        sfTime_asSeconds(sfClock_getElapsedTime(rpg->loader.clock.clock));

    if (time >= 23) {
        scene.scene = "start";
        rpg->start.is_start = true;
        sfClock_restart(rpg->clock.clock);
        free_loader(rpg);
    }
}

void display_loader(rpg_t *rpg)
{
    loader_first_image_open(rpg);
    loader_image_open(rpg);
    change_loader_scene(rpg);
}

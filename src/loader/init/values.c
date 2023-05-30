/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** values
*/

#include "rpg.h"

static void init_loader_function(rpg_t *rpg)
{
    init_loader_fade_rect(rpg);
    init_loader_image(rpg);
}

static void init_loader_struct(rpg_t *rpg)
{
    rpg->loader.sprite = my_calloc(5, sizeof(struct loader_sprite));
    rpg->loader.rect = my_calloc(3, sizeof(struct loader_rect));
    rpg->loader.clock.clock = sfClock_create();
    rpg->loader.alpha = 0;
}

void init_loader_values(rpg_t *rpg)
{
    rpg->loader.music = sfMusic_createFromFile("assets/sfxs/loader_mus.ogg");
    sfMusic_setVolume(rpg->loader.music, 100);
    rpg->loader.time.close_start_time = 15000;
    rpg->loader.time.close_end_time = 22000;
    rpg->loader.time.open_start_time = 8000;
    rpg->loader.time.open_end_time = 15000;
    rpg->loader.time.y = 1;
    init_loader_struct(rpg);
    init_loader_function(rpg);
}

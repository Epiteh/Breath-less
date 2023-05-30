/*
** EPITECH PROJECT, 2023
** Epiteh-Engine
** File description:
** values
*/

#include "rpg.h"

static void init_clock(rpg_t *rpg)
{
    rpg->clock.clock = sfClock_create();
    rpg->clock.time = sfClock_getElapsedTime(rpg->clock.clock);
    rpg->clock.seconds = rpg->clock.time.microseconds / 1000000.0;
}

static void init_window(rpg_t *rpg)
{
    rpg->window.mode.width = 1920;
    rpg->window.mode.height = 1080;
    rpg->fps.fps = 60;
    rpg->window.mode.bitsPerPixel = rpg->fps.fps;
    rpg->window.window = sfRenderWindow_create(rpg->window.mode,
        "Epiteh, NBC Signature.", sfResize | sfClose, NULL);
}

static void init_background(rpg_t *rpg)
{
    rpg->background.texture =
        sfTexture_createFromFile("assets/menu.png", NULL);
    rpg->background.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->background.sprite,
        rpg->background.texture, sfTrue);
    sfSprite_setPosition(rpg->background.sprite, (sfVector2f){0, 0});
    rpg->background.map_render_texture = sfRenderTexture_create(2200, 2200,
        sfTrue);
    rpg->background.map_sprite = sfSprite_create();
}

static void init_other_values(rpg_t *rpg)
{
    init_map(rpg);
    init_mini_map(rpg);
    init_collectibles(rpg);
    init_scenes_values(rpg);
    init_menues_values(rpg);
    init_save_values(rpg);
    init_mission(rpg);
    init_hud_background_menu(rpg);
    init_draw_text_hud(rpg);
}

void init_values(rpg_t *rpg)
{
    rpg->view.view = sfView_create();
    init_font(rpg);
    init_three_d_map(rpg);
    init_clock(rpg);
    init_window(rpg);
    init_loader_values(rpg);
    init_fight_background(rpg);
    init_background(rpg);
    init_sprite(rpg);
    init_fights(&rpg->fights);
    init_choices(&rpg->fights);
    init_place_hud(&rpg->fights);
    init_control_hud(&rpg->fights);
    init_view(rpg);
    init_other_values(rpg);
}

/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** values
*/

#include "rpg.h"

static void init_start_bg_menu(rpg_t *rpg)
{
    rpg->start.sprite_menu[0].sprite = sfSprite_create();
    rpg->start.sprite_menu[0].texture =
        sfTexture_createFromFile("assets/menu/start/menu.png", NULL);
    sfSprite_setTexture(rpg->start.sprite_menu[0].sprite,
        rpg->start.sprite_menu[0].texture, sfTrue);
    sfSprite_setPosition(rpg->start.sprite_menu[0].sprite,
        (sfVector2f){0, -15});
}

static void init_start_menu_buttons(rpg_t *rpg)
{
    init_start_bg_menu(rpg);
    init_start_credit(rpg);
    init_start_load(rpg);
    init_start_quit(rpg);
    init_start_settings(rpg);
    init_start_new(rpg);
    start_init_how_to_play_bg(rpg);
    init_start_how_to_play_img(rpg);
}

static void init_start_menu_struct(rpg_t *rpg)
{
    rpg->start.is_start = false;
    rpg->start.is_how_to_play = false;
    rpg->start.sprite_menu = my_calloc(3, sizeof(struct sprite_start));
    rpg->start.button = my_calloc(5, sizeof(struct my_button));
    rpg->start.txt_menu = my_calloc(5, sizeof(struct txt_start));
    rpg->start.escape_menu = false;
    rpg->start.buffer = sfSoundBuffer_createFromFile("assets/sfxs/click.ogg");
    rpg->start.click = sfSound_create();
    rpg->start.music = sfMusic_createFromFile("assets/sfxs/menu_mus.ogg");
    sfSound_setBuffer(rpg->start.click, rpg->start.buffer);
    sfSound_setVolume(rpg->start.click, 40);
    sfMusic_setVolume(rpg->start.music, 40);
    sfMusic_setLoop(rpg->start.music, sfTrue);
}

void init_start_menu_values(rpg_t *rpg)
{
    init_start_menu_struct(rpg);
    init_start_menu_buttons(rpg);
}

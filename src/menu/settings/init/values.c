/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** values
*/

#include "rpg.h"

static void init_settings_background(rpg_t *rpg)
{
    rpg->settings.sprite[0].texture =
        sfTexture_createFromFile("assets/menu/settings/menu.png", NULL);
    rpg->settings.sprite[0].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->settings.sprite[0].sprite,
        rpg->settings.sprite[0].texture, sfTrue);
    sfSprite_setScale(rpg->settings.sprite[0].sprite,
        (sfVector2f){1, 0.95});
}

static void init_screen_size(rpg_t *rpg)
{
    rpg->settings.screen.is_1920 = false;
    rpg->settings.screen.is_1600 = false;
    rpg->settings.screen.is_800 = false;
    init_choose_button(rpg);
    init_middle_button(rpg);
    init_normal_button(rpg);
    init_small_button(rpg);
}

static void init_settings_buttons(rpg_t *rpg)
{
    init_screen_size(rpg);
    init_settings_background(rpg);
    init_fps_number(rpg);
    init_add_fps(rpg);
    init_remove_fps(rpg);
    init_hdr_number(rpg);
    init_sound_settings(rpg);
    init_interaction_key_button(rpg);
}

static void init_settings_struct(rpg_t *rpg)
{
    rpg->settings.sprite = my_calloc(3, sizeof(struct sprite_settings));
    rpg->settings.txt = my_calloc(11, sizeof(struct txt_settings));
    rpg->settings.button = my_calloc(9, sizeof(struct my_button));
    rpg->settings.open_settings = false;
    rpg->settings.screen_size = false;
    rpg->settings.buffer =
        sfSoundBuffer_createFromFile("assets/sfxs/click2.ogg");
    rpg->settings.click = sfSound_create();
    rpg->settings.quitbuffer =
        sfSoundBuffer_createFromFile("assets/sfxs/quitclick.ogg");
    rpg->settings.quitclick = sfSound_create();
    sfSound_setBuffer(rpg->settings.click, rpg->settings.buffer);
    sfSound_setBuffer(rpg->settings.quitclick, rpg->settings.quitbuffer);
    sfSound_setVolume(rpg->settings.click, 40);
    sfSound_setVolume(rpg->settings.quitclick, 40);
    rpg->settings.is_setting = false;
}

void init_settings_values(rpg_t *rpg)
{
    init_settings_struct(rpg);
    init_settings_buttons(rpg);
}

/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** settings
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#pragma once

struct rect_settings {
    sfRectangleShape *rect;
    sfTexture *texture;
    sfSprite *sprite;
};
struct sprite_settings {
    sfSprite *sprite;
    sfTexture *texture;
};
struct txt_settings {
    sfText *text;
};
struct screen_size {
    char *str;
    bool is_1600;
    bool is_1920;
    bool is_800;
};
struct settings_menu {
    struct rect_settings *rect;
    struct sprite_settings *sprite;
    struct txt_start *txt;
    struct my_button *button;
    sfSound *click;
    sfSoundBuffer *buffer;
    sfSound *quitclick;
    sfSoundBuffer *quitbuffer;
    bool open_settings;
    bool screen_size;
    char interaction_key;
    struct screen_size screen;
    bool is_setting;
};

/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** start
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdbool.h>

#pragma once

// Struct Start
    struct rect_start {
        sfRectangleShape *rect;
        sfTexture *texture;
        sfSprite *sprite;
    };
    struct sprite_start {
        sfSprite *sprite;
        sfTexture *texture;
    };
    struct txt_start {
        sfText *text;
    };
    struct start_menu {
        struct rect_start *rect_menu;
        struct sprite_start *sprite_menu;
        struct txt_start *txt_menu;
        struct my_button *button;
        sfSound *click;
        sfSoundBuffer *buffer;
        sfMusic *music;
        bool escape_menu;
        bool is_start;
        bool is_how_to_play;
    };

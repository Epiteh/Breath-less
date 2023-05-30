/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** char
*/

#include <SFML/Graphics.h>

#pragma once

// Character Creator
    struct rect_char {
        sfRectangleShape *rect;
        sfTexture *texture;
        sfSprite *sprite;
    };

    struct sprite_char {
        sfSprite *sprite;
        sfTexture *texture;
    };

    struct txt_char {
        sfText *text;
        sfFont *font;
    };

    struct char_menu {
        struct rect_char *rect;
        struct sprite_char *sprite;
        struct txt_char *txt;
        struct my_button *button;
        sfIntRect rect_size;
        unsigned int index;
        bool char_open;
        bool is_hover;
        int skills;
        int river;
        int lucy;
    };

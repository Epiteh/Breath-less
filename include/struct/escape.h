/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** escape
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#pragma once

// Struct Escape
    struct rect_menu {
        sfRectangleShape *rect;
        sfTexture *texture;
        sfSprite *sprite;
    };

    struct sprite_menu {
        sfSprite *sprite;
        sfTexture *texture;
    };

    struct txt_menu {
        sfText *text;
        sfFont *font;
    };

    struct escape_menu {
        struct rect_menu *rect_menu;
        struct sprite_menu *sprite_menu;
        struct txt_menu *txt_menu;
        struct my_button *button;
        bool escape_menu;
    };

/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** inventory
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#pragma once

struct rect_inventory {
    sfRectangleShape *rect;
    sfTexture *texture;
    sfSprite *sprite;
};
struct sprite_inventory {
    sfSprite *sprite;
    sfTexture *texture;
};
struct txt_inventory {
    sfText *text;
    sfFont *font;
};
struct inventory_menu {
    struct rect_inventory *rect;
    struct sprite_inventory *sprite;
    struct txt_inventory *txt;
    struct my_button *button;
    bool inventory_open;
    bool is_first;
    bool is_second;
    bool is_third;
    bool is_fourth;
    bool is_fifth;
    bool is_sixth;
};

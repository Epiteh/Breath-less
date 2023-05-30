/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#include <SFML/Graphics.h>

#pragma once

// Player
    struct sprite {
        char *sprite_path;
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f position;
        sfVector2f screen_pos;
        sfClock *clock;
        sfIntRect rect;
        sfTexture *texture_bg;
        sfSprite *sprite_bg;
        sfImage *image_bg;
        sfVector2f sprite_size;
        sfVector2f hitbox_size;
        char *down;
        char *up;
        char *left;
        char *right;
        int lower_x;
        int lower_y;
        int upper_x;
        int upper_y;
    };
    // Player View
    struct view {
        sfSprite *Smap;
        sfTexture *Tmap;
        sfIntRect rect;
        int screenW;
        int screenH;
        sfView *view;
        int lower_x;
        int lower_y;
        int upper_x;
        int upper_y;
    };
    // Player Position
    typedef struct tp_s {
        sfVector2f player_pos;
    } tp_t;

/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** loader
*/

#include <SFML/Graphics.h>

#pragma once
struct loader_clock {
    sfClock *clock;
    sfTime time;
    float seconds;
};
struct loader_rect {
    sfRectangleShape *rect;
};
struct loader_time {
    int close_start_time;
    int close_end_time;
    int open_start_time;
    int open_end_time;
    unsigned int y;
};
struct loader_sprite {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
};
struct loader {
    struct loader_clock clock;
    struct loader_rect *rect;
    struct loader_sprite *sprite;
    sfUint8 alpha;
    sfMusic *music;
    struct loader_time time;
};

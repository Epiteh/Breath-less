/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** save
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#pragma once
// Save Game

    // Save rect
    struct save_rect {
        sfRectangleShape *rect;
        sfTexture *texture;
        sfSprite *sprite;
    };

    // Save text
    struct save_txt {
        sfText *text;
        sfFont *font;
    };

    // Save Info
    struct save_info {
        bool escape_bar_done;
        bool catch_knife_done;
        bool go_place_done;
        bool go_safe_place_done;
        bool do_place_fight_done;
        bool go_control_zone_done;
        bool do_control_fight_done;
        bool go_back_safe_place_done;
        bool escape_bar;
        bool catch_knife;
        bool go_place;
        bool go_safe_place;
        bool do_place_fight;
        bool go_control_zone;
        bool do_control_fight;
        bool go_back_safe_place;
        int level;
        int xp;
        int hp;
        int pos_x;
        int pos_y;
        char scene[20];
    };

    // Save Sprite
    struct save_sprite {
        sfSprite *sprite;
        sfTexture *texture;
    };

    // Save Main
    struct save {
        struct save_rect *rect;
        struct save_txt *txt;
        struct my_button *button;
        struct save_name *name;
        struct save_sprite *sprite;
        struct save_info info;
        char *input;
        bool is_save;
        bool is_load;
    };

/*
** EPITECH PROJECT, 2023
** read_html_file
** File description:
** my
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#pragma once

// Collectible
    typedef struct {
        sfSprite *sprite;
        sfSprite *e_interaction;
        sfTexture *texture;
        sfVector2f pos;
        sfRectangleShape *rect;
        sfVector2f rect_pos;
        bool get;
        bool collision;
    } knife_t;

    typedef struct {
        sfSprite *sprite;
        sfFont* font;
        char *message_content;
        sfText *message;
        sfSprite *e_interaction;
        sfTexture *texture;
        sfVector2f pos;
        sfRectangleShape *rect;
        sfRectangleShape *text_rect;
        sfVector2f rect_pos;
        unsigned int letter_counter;
        bool is_taking;
        bool collision;
    } main_place_npc_t;

    typedef struct {
        sfSprite *sprite;
        sfFont* font;
        char *message_content;
        sfText *message;
        sfSprite *e_interaction;
        sfTexture *texture;
        sfVector2f pos;
        sfRectangleShape *rect;
        sfRectangleShape *text_rect;
        sfVector2f rect_pos;
        unsigned int letter_counter;
        bool is_taking;
        bool collision;
    } bar_npc_t;

    typedef struct {
        sfSprite *sprite;
        sfFont* font;
        char *message_content;
        sfText *message;
        sfSprite *e_interaction;
        sfTexture *texture;
        sfVector2f pos;
        sfRectangleShape *rect;
        sfRectangleShape *text_rect;
        sfVector2f rect_pos;
        unsigned int letter_counter;
        bool is_taking;
        bool collision;
    } safe_place_t;

    typedef struct {
        sfSprite *sprite;
        sfFont* font;
        char *message_content;
        sfText *message;
        sfSprite *e_interaction;
        sfTexture *texture;
        sfVector2f pos;
        sfRectangleShape *rect;
        sfRectangleShape *text_rect;
        sfVector2f rect_pos;
        unsigned int letter_counter;
        bool is_taking;
        bool collision;
    } control_zone_t;

    typedef struct {
        sfSprite *first_mate_sprite;
        sfTexture *first_mate_texture;
        sfSprite *second_mate_sprite;
        sfTexture *second_mate_texture;
        sfSprite *sprite;
        sfFont* font;
        char *message_content;
        sfText *message;
        sfSprite *e_interaction;
        sfTexture *texture;
        sfVector2f pos;
        sfRectangleShape *rect;
        sfRectangleShape *text_rect;
        sfVector2f rect_pos;
        unsigned int letter_counter;
        bool is_taking;
        bool collision;
    } back_safe_place_npc_t;

    typedef struct {
        knife_t knife;
        main_place_npc_t main_place_npc;
        bar_npc_t bar_npc;
        safe_place_t safe_place_npc;
        control_zone_t control_zone_npc;
        back_safe_place_npc_t back_safe_place_npc;
        sfClock *npc_text_clock;
        sfTexture *texture_first_e_inter;
        sfTexture *texture_second_e_inter;
        sfTexture *texture;
        sfClock *clock;
        unsigned int last_second;
    } collectible_t;

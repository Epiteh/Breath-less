/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** fight
*/

#include <SFML/Graphics.h>

#pragma once

// Struct Fight
    struct attacks {
        char *name;
        int damage;
        int speed;
        bool available;
    };

    struct player_datas {
        int hp;
        int defense;
        int level;
        int xp;
        int max_hp;
        int damage;
        int speed;
        unsigned int mindfulness;
        struct attacks *attacks;
        bool dead;
    };

    struct player {
        sfClock *clock;
        sfSprite *sprite;
        sfIntRect rect;
        sfTexture *texture;
        sfVector2f position;
        struct player_datas datas;
    };

    struct place {
        sfClock *clock;
        int enemies_left;
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f *enm_pos;
        struct player *enemies;
        struct choices *choices;
        struct hud *hud;
        int choice;
        bool fight;
    };

    struct control {
        sfClock *clock;
        sfSprite *sprite;
        sfTexture *texture;
        struct player enemy;
        struct choices *choices;
        struct hud *hud;
        int choice;
        bool fight;
    };

    struct choices {
        unsigned int actual;
        sfSprite *arrow;
        sfTexture *arrow_texture;
        sfText **text;
        sfVector2f *position;
        sfFont *font;
    };

    struct hud {
        sfSprite *sprite;
        sfTexture *texture;
        sfText *text;
    };

    struct scene {
        sfSprite *sprite;
        sfTexture *texture;
    };

    struct fight_s {
        struct player player;
        struct place place;
        struct control control;
        struct hud *hud;
        struct scene *bg;
        char *tmp;
        int to_attack;
        int is_attacking;
        bool player_turn;
        bool attacked;
        sfBool pressed;
    };

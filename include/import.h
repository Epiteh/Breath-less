/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** import
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include "my.h"
#include "struct/escape.h"
#include "struct/loader.h"
#include "struct/start.h"
#include "struct/settings.h"
#include "struct/hud.h"
#include "struct/inventory.h"
#include "struct/char.h"
#include "struct/collectible.h"
#include "struct/fight.h"
#include "struct/map.h"
#include "struct/player.h"
#include "struct/save.h"

#pragma once

// Main Struct
    // Scene
    struct my_scene {
        char *scene;
    };

    extern struct my_scene scene;
    // Clock
    struct my_clock {
        sfClock *clock;
        sfTime time;
        float seconds;
    };

    // Window
    struct my_window {
        sfRenderWindow *window;
        sfEvent event;
        sfVideoMode mode;
        sfMouseMoveEvent *mouse;
    };

    // Background
    struct background {
        sfTexture *texture;
        sfTexture *three_texture;
        sfSprite *sprite;
        sfSprite *three_sprite;
        sfRenderTexture *map_render_texture;
        sfSprite *map_sprite;
        const sfTexture *map_texture;
    };

    // FPS
    struct fps {
        unsigned int fps;
        char *str;
    };

    // Missions
    typedef struct {
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
    } mission_t;

    // Texts
    typedef struct {
        sfText *text;
        sfSprite *small_sprite;
        sfSprite *large_sprite;
        sfTexture *small_texture;
        sfTexture *large_texture;
        unsigned int letter_counter;
        sfClock *clock;
        bool is_writing;
    } mission_text_t;

#define COCHOICE fights->control.choice
#define PLCHOICE fights->place.choice
#define COACTUAL fights->control.choices[COCHOICE].actual
#define PLACTUAL fights->place.choices[PLCHOICE].actual
#define PLATTACK fights->player.datas.attacks
#define MIND fights->player.datas.mindfulness

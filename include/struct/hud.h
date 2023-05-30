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

// Struct Hud
    typedef struct hud_s {
        sfSprite *mapSprite;
        sfSprite *pointerSprite;
        sfSprite *miniMapSprite;
        sfTexture *mapTexture;
        sfTexture *pointerTexture;
        sfRenderTexture* miniMapTexture;
        sfView* miniMapView;
        sfVector2f player_pos;
        sfTexture *hud_txr;
        sfSprite *hud_spr;
        sfText *life;
        sfText *xp;
        sfText *level;
    } hud_t;

/*
** EPITECH PROJECT, 2023
** MY_RPG 23 avril
** File description:
** hud_map.c
*/
#include "rpg.h"

static int init_texture(rpg_t *rpg)
{
    rpg->hud.mapTexture =
        sfTexture_createFromFile("assets/HUD/map.png", NULL);
    if (!rpg->hud.mapTexture)
        return (84);
    rpg->hud.pointerTexture =
        sfTexture_createFromFile("assets/HUD/pointer.png", NULL);
    if (!rpg->hud.pointerTexture)
        return (84);
    rpg->hud.mapSprite = sfSprite_create();
    rpg->hud.pointerSprite = sfSprite_create();
    sfSprite_setTexture(rpg->hud.mapSprite, rpg->hud.mapTexture, sfTrue);
    sfSprite_setTexture(rpg->hud.pointerSprite, rpg->hud.pointerTexture,
        sfTrue);
    return (0);
}

static void init_map_view(rpg_t *rpg)
{
    sfView_setRotation(rpg->hud.miniMapView, 180.f);
    sfView_setSize(rpg->hud.miniMapView, (sfVector2f){1000, 800});
    rpg->hud.player_pos = (sfVector2f){2175 - 493, 405};
    sfView_setCenter(rpg->hud.miniMapView, rpg->hud.player_pos);
}

static void init_pointer_effect(rpg_t *rpg)
{
    sfSprite_setOrigin(rpg->hud.pointerSprite,
        (sfVector2f) {512 / 2, 512 / 2});
    sfSprite_setPosition(rpg->hud.pointerSprite,
        (sfVector2f){2135 - 390, 405});
    sfSprite_setScale(rpg->hud.pointerSprite,
        (sfVector2f){0.13f, 0.15f});
}

int init_mini_map(rpg_t *rpg)
{
    if (init_texture(rpg) == 84) {
        return (84);
    }
    rpg->hud.miniMapTexture =
        sfRenderTexture_create(1500, 1500, sfFalse);
    if (!rpg->hud.miniMapTexture) {
        return (84);
    }
    rpg->hud.miniMapSprite = sfSprite_create();
    rpg->hud.miniMapView = sfView_create();
    init_map_view(rpg);
    rpg->hud.miniMapSprite = sfSprite_create();
    sfSprite_setPosition(rpg->hud.miniMapSprite,
        (sfVector2f){1525, 20});
    sfSprite_setScale(rpg->hud.miniMapSprite,
        (sfVector2f){0.25f, 0.25f});
    init_pointer_effect(rpg);
    return (0);
}

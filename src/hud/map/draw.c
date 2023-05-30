/*
** EPITECH PROJECT, 2023
** MY_RPG 23 avril
** File description:
** draw.c
*/
#include "rpg.h"

static void draw_minimap(rpg_t *rpg)
{
    const sfTexture* miniMapTexturePtr;

    sfRenderTexture_drawSprite(rpg->hud.miniMapTexture,
        rpg->hud.mapSprite, NULL);
    sfRenderTexture_drawSprite(rpg->hud.miniMapTexture,
        rpg->hud.pointerSprite, NULL);
    miniMapTexturePtr =
        sfRenderTexture_getTexture(rpg->hud.miniMapTexture);
    sfSprite_setTexture(rpg->hud.miniMapSprite,
        miniMapTexturePtr, sfTrue);
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->hud.miniMapSprite, NULL);
}

static void rotate_pointer(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        sfSprite_setRotation(rpg->hud.pointerSprite, 180);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        sfSprite_setRotation(rpg->hud.pointerSprite, 90);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        sfSprite_setRotation(rpg->hud.pointerSprite, 270);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        sfSprite_setRotation(rpg->hud.pointerSprite, 0);
    }
}

static void move_map_view(rpg_t *rpg)
{
    if ((rpg->sprite.position.x > 475) &&
        (rpg->sprite.position.x < 1670)) {
            rpg->hud.player_pos.x = 2175 - rpg->sprite.position.x;
    }
    if ((rpg->sprite.position.y > 383) &&
        (rpg->sprite.position.y < 1788)) {
            rpg->hud.player_pos.y = rpg->sprite.position.y + 20;
    }
}

void minimap(rpg_t *rpg)
{
    move_map_view(rpg);
    rotate_pointer(rpg);
    sfView_setCenter(rpg->hud.miniMapView, rpg->hud.player_pos);
    sfSprite_setPosition(rpg->hud.pointerSprite, (sfVector2f){2175 -
        rpg->sprite.position.x, rpg->sprite.position.y + 20});
    sfRenderTexture_setView(rpg->hud.miniMapTexture,
        rpg->hud.miniMapView);
    sfRenderWindow_setView(rpg->window.window,
        sfRenderWindow_getDefaultView(rpg->window.window));
    draw_minimap(rpg);
}

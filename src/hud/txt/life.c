/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** life
*/

#include "rpg.h"
#include <stdlib.h>

void init_draw_text_hud(rpg_t *rpg)
{
    rpg->hud.life = sfText_create();
    rpg->hud.xp = sfText_create();
    rpg->hud.level = sfText_create();
    sfText_setFont(rpg->hud.life, rpg->font);
    sfText_setFont(rpg->hud.xp, rpg->font);
    sfText_setFont(rpg->hud.level, rpg->font);
    sfText_setCharacterSize(rpg->hud.life, 20);
    sfText_setCharacterSize(rpg->hud.xp, 20);
    sfText_setCharacterSize(rpg->hud.level, 20);
    sfText_setPosition(rpg->hud.life, (sfVector2f){185, 850});
    sfText_setPosition(rpg->hud.xp, (sfVector2f){195, 902});
    sfText_setPosition(rpg->hud.level, (sfVector2f){195, 957});
    sfText_setColor(rpg->hud.life, sfBlack);
    sfText_setColor(rpg->hud.xp, sfBlack);
    sfText_setColor(rpg->hud.level, sfBlack);
}

static void display_draw_text_hud2(rpg_t *rpg)
{
    char *life = my_calloc(10, sizeof(char));
    my_itoa(rpg->fights.player.datas.hp, life);
    char *xp = my_calloc(10, sizeof(char));
    my_itoa(rpg->fights.player.datas.xp, xp);
    char *level = my_calloc(10, sizeof(char));
    my_itoa(rpg->fights.player.datas.level, level);

    sfText_setString(rpg->hud.life, life);
    sfText_setString(rpg->hud.xp, xp);
    sfText_setString(rpg->hud.level, level);
    sfRenderWindow_drawText(rpg->window.window, rpg->hud.life, NULL);
    sfRenderWindow_drawText(rpg->window.window, rpg->hud.xp, NULL);
    sfRenderWindow_drawText(rpg->window.window, rpg->hud.level, NULL);
    free(life);
    free(xp);
    free(level);
}

void display_draw_text_hud(rpg_t *rpg)
{
    if (my_strcmp(scene.scene, "start") != 0
        && my_strcmp(scene.scene, "fight") != 0
            && my_strcmp(scene.scene, "loader") != 0
                && my_strcmp(scene.scene, "boss") != 0
                    && my_strcmp(scene.scene, "char_creator") != 0) {
    sfRenderWindow_setView(rpg->window.window,
        sfRenderWindow_getDefaultView(rpg->window.window));
    display_draw_text_hud2(rpg);
    }
}

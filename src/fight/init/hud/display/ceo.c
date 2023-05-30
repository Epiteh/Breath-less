/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** hud
*/

#include "rpg.h"

static void display_place(rpg_t *rpg, struct fight_s *fights)
{
    for (unsigned int i = 0; i < 3; i++) {
        check_player_datas(fights, i);
    }
    for (unsigned int j = 5; j < 8; j++) {
        check_enemies_datas(fights, j);
    }
    for (unsigned int k = 0; k < 8; k++) {
        sfRenderWindow_drawSprite(rpg->window.window,
            fights->place.hud[k].sprite, NULL);
        sfRenderWindow_drawText(rpg->window.window,
            fights->place.hud[k].text, NULL);
    }
}

static void display_control(rpg_t *rpg, struct fight_s *fights)
{
    for (unsigned int i = 0; i < 3; i++) {
        check_player_datas(fights, i);
    }
    check_boss_datas(fights);
    for (unsigned int k = 0; k < 7; k++) {
        sfRenderWindow_drawSprite(rpg->window.window,
            fights->control.hud[k].sprite, NULL);
        sfRenderWindow_drawText(rpg->window.window,
            fights->control.hud[k].text, NULL);
    }
}

void display_fight_hud(rpg_t *rpg, struct fight_s *fights)
{
    if (my_strcmp(scene.scene, "fight") == 0)
        display_place(rpg, fights);
    if (my_strcmp(scene.scene, "boss") == 0)
        display_control(rpg, fights);
}

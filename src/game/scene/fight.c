/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** fight
*/

#include "rpg.h"

static void handle_two_fight_scene(rpg_t *rpg)
{
    if (my_strcmp(scene.scene, "fight") == 0) {
        rpg->fights.place.fight = true;
        rpg->fights.control.fight = false;
    }
    if (my_strcmp(scene.scene, "boss") == 0) {
        rpg->fights.place.fight = false;
        rpg->fights.control.fight = true;
    }
    display_fight_background(rpg);
    display_fight_hud(rpg, &rpg->fights);
    fightscene(rpg, &rpg->fights);
}

void handle_fight(rpg_t *rpg)
{
    if (my_strcmp(scene.scene, "fight") == 0 ||
        my_strcmp(scene.scene, "boss") == 0) {
        handle_two_fight_scene(rpg);
        if ((rpg->fights.place.fight || rpg->fights.control.fight)
            && !rpg->fights.player_turn) {
                    enemies_event(&rpg->fights);
        }
        fight_process(rpg, &rpg->fights);
        display_escape_menu(rpg);
        display_settings(rpg);
    }
}

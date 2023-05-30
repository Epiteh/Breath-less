/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** mission
*/

#include "rpg.h"

void mission_scene(rpg_t *rpg)
{
    sfRenderWindow_setView(rpg->window.window,
        sfRenderWindow_getDefaultView(rpg->window.window));
    if (my_strcmp(scene.scene, "bar") == 0)
        display_bar_mission_text(rpg);
    if (rpg->mission.catch_knife)
        display_knife_mission_text(rpg);
    if (rpg->mission.go_place)
        display_main_place_mission_text(rpg);
    if (rpg->mission.go_safe_place)
        display_find_safe_place_mission_text(rpg);
    if (rpg->mission.go_control_zone)
        display_control_zone_mission_text(rpg);
    if (rpg->mission.do_control_fight && my_strcmp(scene.scene, "boss") != 0)
        display_do_fight_mission_text(rpg);
    if (rpg->mission.go_back_safe_place &&
        !rpg->mission.go_back_safe_place_done) {
            display_back_safe_place_mission_text(rpg);
    }
}

/*
** EPITECH PROJECT, 2023
** Epiteh-Engine
** File description:
** scenes
*/

#include "rpg.h"

void init_menues_values(rpg_t *rpg)
{
    init_settings_values(rpg);
    init_inventory_values(rpg);
    init_char_values(rpg);
    init_settings_values(rpg);
    init_inventory_values(rpg);
    init_start_menu_values(rpg);
    init_escape_menu_values(rpg);
}

void init_scenes_values(rpg_t *rpg)
{
    init_control_zone_scene(rpg);
    init_factory_basement_scene(rpg);
    init_factory_scene(rpg);
    init_logos_entrance_scene(rpg);
    init_logos_machine_scene(rpg);
    init_logos_office_scene(rpg);
    init_safe_place_scene(rpg);
    init_bar_scene(rpg);
    init_loader_values(rpg);
}

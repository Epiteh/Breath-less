/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** hud
*/

#include "rpg.h"

static void init_player_hud(struct fight_s *fights)
{
    sfColor color = {152, 255, 255, 255};

    player_life(fights, color);
    player_speed(fights, color);
    player_mind(fights, color);
    player_lvl(fights, color);
}

static void init_plenemies_hud(struct fight_s *fights)
{
    sfColor color = {255, 218, 255, 255};

    enemies_lvl(fights, color);
    enemies_life(fights, color);
}

static void init_boss_hud(struct fight_s *fights)
{
    sfColor color = {255, 218, 255, 255};

    boss_lvl(fights, color);
    boss_life(fights, color);
    boss_mind(fights, color);
}

void init_control_hud(struct fight_s *fights)
{
    init_player_hud(fights);
    init_boss_hud(fights);
}

void init_place_hud(struct fight_s *fights)
{
    fights->place.hud = my_calloc(sizeof(*fights->place.hud), 8);
    fights->control.hud = my_calloc(sizeof(*fights->control.hud), 7);
    init_player_hud(fights);
    init_plenemies_hud(fights);
}

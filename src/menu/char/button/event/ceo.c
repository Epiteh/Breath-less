/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** ceo
*/

#include "rpg.h"

void char_creator_event(rpg_t *rpg)
{
    left_player_event(rpg);
    right_player_event(rpg);
    speed_creator_event(rpg);
    strength_creator_event(rpg);
    intelligence_creator_event(rpg);
    start_game_creator_event(rpg);
}

/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** datas
*/

#include "rpg.h"

static void init_player_coattacks(struct fight_s *fights)
{
    fights->player.datas.attacks =
        my_calloc(sizeof(*fights->player.datas.attacks), 3);
    fights->player.datas.attacks[0].name = "Crossed Slash Combo";
    fights->player.datas.attacks[0].damage = 25;
    fights->player.datas.attacks[0].speed = 15;
    fights->player.datas.attacks[0].available = true;
    fights->player.datas.attacks[1].name = "Woke Blade";
    fights->player.datas.attacks[1].damage = 40;
    fights->player.datas.attacks[1].speed = 10;
    fights->player.datas.attacks[1].available = true;
    fights->player.datas.attacks[2].name = "Awakened Thinking";
    fights->player.datas.attacks[2].damage = 100;
    fights->player.datas.attacks[2].speed = 100;
    fights->player.datas.attacks[2].available = false;
}

void upd8_player_datas(struct fight_s *fights)
{
    if (my_strcmp(scene.scene, "boss") == 0) {
        fights->player.datas.max_hp = 850;
        fights->player.datas.hp = 850;
        fights->player.datas.defense = 2.5;
        fights->player.datas.level = 6;
        fights->player.datas.mindfulness = 100;
        fights->player.datas.speed = 200;
        fights->player.datas.damage = 100;
        fights->player.datas.xp = 0;
        fights->place.enemies_left = 10;
        init_player_coattacks(fights);
    }
}

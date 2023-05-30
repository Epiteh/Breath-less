/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** fight
*/

#include "rpg.h"
#include <stdlib.h>
#include <stdio.h>

static void check_deaths(struct fight_s *fights)
{
    for (unsigned int i = 0; i < 3; i++) {
        if (fights->place.enemies[i].datas.hp <= 0
            && !fights->place.enemies[i].datas.dead) {
            fights->place.enemies[i].datas.hp = 0;
            sfSprite_setPosition(fights->place.enemies[i].sprite,
                (sfVector2f){-100, -100});
            fights->place.enemies[i].datas.dead = true;
            fights->place.enemies_left -= 1;
        }
    }
}

static void end_of_control_fight(rpg_t *rpg, struct fight_s *fights)
{
    if (fights->control.enemy.datas.hp <= 10 && rpg->mission.do_control_fight) {
        scene.scene = "control_zone";
        fights->place.fight = false;
        rpg->fights.player.datas.xp += 30;
        rpg->fights.player.datas.level += 1;
        valid_boss_fight(rpg);
    }
    if (fights->player.datas.hp <= 10 && rpg->mission.do_control_fight) {
        scene.scene = "control_zone";
        fights->control.fight = false;
        rpg->mission.do_control_fight = false;
    }
    if (fights->player.datas.mindfulness <= 0 &&
        rpg->mission.do_control_fight) {
        scene.scene = "control_zone";
        fights->control.fight = false;
        valid_boss_fight(rpg);
    }
}

static void end_of_fight(rpg_t *rpg, struct fight_s *fights)
{
    if (fights->place.enemies_left == 0 && rpg->mission.do_place_fight) {
        scene.scene = "game";
        fights->place.fight = false;
        rpg->fights.player.datas.xp += 30;
        rpg->fights.player.datas.level += 1;
        do_main_place_fight(rpg);
    }
    if (fights->player.datas.hp <= 0 && rpg->mission.do_place_fight) {
        scene.scene = "game";
        fights->place.fight = false;
    }
    if (fights->player.datas.mindfulness <= 0 && rpg->mission.do_place_fight) {
        scene.scene = "game";
        fights->place.fight = false;
        do_main_place_fight(rpg);
    }
    end_of_control_fight(rpg, fights);
}

void fight_process(rpg_t *rpg, struct fight_s *fights)
{
    if (fights->place.fight) {
        check_deaths(fights);
    }
    if (fights->player.datas.hp >= fights->player.datas.max_hp) {
        fights->player.datas.hp = fights->player.datas.max_hp;
    }
    if (fights->player.datas.mindfulness >= 100) {
        fights->player.datas.mindfulness = 100;
    }
    end_of_fight(rpg, fights);
}

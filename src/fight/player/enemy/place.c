/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** place
*/

#include "rpg.h"
#include "stdlib.h"

static void attacks_cases(struct fight_s *fights, int attack, int tmp, int dmg)
{
    if (attack == 0) {
        fights->player.datas.hp -= dmg / fights->player.datas.defense;
    } else if (attack == 1) {
        fights->player.datas.hp -= dmg / fights->player.datas.defense;
    } else {
        fights->player.datas.hp -=
            fights->place.enemies[tmp].datas.attacks[2].damage
                / fights->player.datas.defense;
    }
}

static void enemies_attack(struct fight_s *fights)
{
    int attack = rand() % 3;
    int tmp = fights->is_attacking;
    int dmg = fights->place.enemies[tmp].datas.attacks[attack].damage
        / fights->player.datas.defense;
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(fights->place.clock));

    sfSprite_setPosition(fights->place.choices[0].arrow,
        (sfVector2f){fights->place.enm_pos[tmp].x + 100,
            fights->place.enm_pos[tmp].y - 40});
    if (fights->place.enemies[tmp].datas.hp <= 0)
        fights->is_attacking += 1;
    if (fights->place.enemies[fights->is_attacking].datas.hp > 0
        && sec >= 1.5) {
        attacks_cases(fights, attack, tmp, dmg);
        fights->is_attacking += 1;
        fights->player.datas.mindfulness -= 3 + rand() % 2;
        sfClock_restart(fights->place.clock);
    }
}

void place_enemies_event(struct fight_s *fights)
{
    if (fights->attacked) {
        fights->place.enemies[fights->to_attack].datas.hp -=
            fights->player.datas.damage *
                ((float)fights->player.datas.speed / 100)
                    + ((float)fights->player.datas.mindfulness / 10);
        fights->attacked = false;
    }
    enemies_attack(fights);
    if (fights->is_attacking == 3) {
        fights->player.datas.speed = 100;
        fights->player_turn = true;
        sfSprite_setRotation(fights->place.choices[0].arrow, 0);
        sfSprite_setPosition(fights->place.choices[PLCHOICE].arrow,
            (sfVector2f){485, 832});
    }
}

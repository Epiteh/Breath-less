/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** control
*/

#include "rpg.h"
#include "stdlib.h"

static void boss_cases(struct fight_s *fights, int attack, int dmg)
{
    if (attack == 0)
        fights->player.datas.hp -= dmg / fights->player.datas.defense;
    else if (attack == 1)
        fights->player.datas.hp -= dmg / fights->player.datas.defense;
    else
        fights->player.datas.hp -= dmg / fights->player.datas.defense;
}

static void boss_attack(struct fight_s *fights)
{
    int attack = rand() % 3;
    int dmg = fights->control.enemy.datas.attacks[attack].damage
        / fights->player.datas.defense;
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(fights->control.clock));

    sfSprite_setPosition(fights->control.choices[0].arrow,
        (sfVector2f){fights->control.choices[3].position[0].x + 82,
            fights->control.choices[3].position[0].y - 45});
    if (fights->control.enemy.datas.hp > 0 && sec >= 2) {
        boss_cases(fights, attack, dmg);
        fights->player.datas.mindfulness -= 3 + rand() % 2;
        fights->player_turn = true;
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {fights->control.choices[0].position[0].x - 65,
                fights->control.choices[0].position[0].y - 8});
        sfClock_restart(fights->control.clock);
    }
}

void control_boss_event(struct fight_s *fights)
{
    if (fights->attacked) {
        fights->control.enemy.datas.hp -=
            fights->player.datas.damage *
                ((float)fights->player.datas.speed / 100)
                    + ((float)fights->player.datas.mindfulness / 10);
        fights->attacked = false;
    }
    boss_attack(fights);
}

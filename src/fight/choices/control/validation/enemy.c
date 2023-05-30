/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** enemy
*/

#include "rpg.h"

void boss_validation(struct fight_s *fights)
{
    if (COCHOICE == 1 && COACTUAL != 3 && COACTUAL != 4 && !fights->pressed) {
        fights->pressed = sfTrue;
        fights->player.datas.damage = PLATTACK[COACTUAL].damage;
        COCHOICE = 3;
        COACTUAL = 2;
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {fights->control.choices[3].position[0].x + 82,
                fights->control.choices[3].position[0].y - 45});
    }
}

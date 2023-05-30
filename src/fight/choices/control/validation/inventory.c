/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** inventory
*/

#include "rpg.h"
#include "stdlib.h"

static void valid_from_first(struct fight_s *fights, sfVector2f tmp2)
{
    if (COCHOICE == 2 && COACTUAL == 0 && !fights->pressed) {
        fights->pressed = sfTrue;
        fights->player.datas.speed += 20;
        MIND += 12 * ((float)fights->player.datas.speed / 100);
        COCHOICE = 0;
        COACTUAL = 3;
        tmp2 = fights->control.choices[COCHOICE].position[COACTUAL - 3];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

static void valid_from_last(struct fight_s *fights, sfVector2f tmp2)
{
    if (COCHOICE == 2 && COACTUAL == 1 && !fights->pressed) {
        fights->pressed = sfTrue;
        fights->player.datas.hp += 40;
        MIND += 5 + rand() % 8;
        COCHOICE = 0;
        COACTUAL = 3;
        tmp2 = fights->control.choices[COCHOICE].position[COACTUAL - 3];
        sfSprite_setPosition(fights->control.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

void inventory_boss_vld(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    valid_from_first(fights, tmp2);
    valid_from_last(fights, tmp2);
}

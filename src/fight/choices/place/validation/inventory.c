/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** inventory
*/

#include "rpg.h"
#include <stdlib.h>

static void valid_from_first(struct fight_s *fights, sfVector2f tmp2)
{
    if (PLCHOICE == 2 && PLACTUAL == 0 && !fights->pressed) {
        fights->pressed = sfTrue;
        fights->player.datas.speed += 20;
        fights->player.datas.mindfulness += (12 *
            ((float)fights->player.datas.speed / 100));
        PLCHOICE = 0;
        PLACTUAL = 3;
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL - 3];
        sfSprite_setPosition(fights->place.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

static void valid_from_last(struct fight_s *fights, sfVector2f tmp2)
{
    if (PLCHOICE == 2 && PLACTUAL == 1 && !fights->pressed) {
        fights->pressed = sfTrue;
        fights->player.datas.hp += 40;
        fights->player.datas.mindfulness += (5 + rand() % 8);
        PLCHOICE = 0;
        PLACTUAL = 3;
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL - 3];
        sfSprite_setPosition(fights->place.choices[0].arrow, (sfVector2f)
            {tmp2.x - 65, tmp2.y - 8});
    }
}

void inventory_validation(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    valid_from_first(fights, tmp2);
    valid_from_last(fights, tmp2);
}

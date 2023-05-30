/*
** EPITECH PROJECT, 2023
** sprite.c
** File description:
** player's animation
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>
#include "rpg.h"

void animation(rpg_t *rpg)
{
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(rpg->sprite.clock));

    if (sec >= 0.13) {
        if ((rpg->sprite.rect.left + rpg->sprite.rect.width) >= 128) {
            rpg->sprite.rect.left = 0;
        } else {
            rpg->sprite.rect.left += 32;
        }
        sfClock_restart(rpg->sprite.clock);
    }
}

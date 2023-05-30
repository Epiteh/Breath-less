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

void boss_animation(struct fight_s *fights)
{
    float sec = sfTime_asSeconds(
        sfClock_getElapsedTime(fights->control.enemy.clock));

    if (sec >= 0.26) {
        if ((fights->control.enemy.rect.left +
            fights->control.enemy.rect.width) >= 256) {
            fights->control.enemy.rect.left = 0;
        } else {
            fights->control.enemy.rect.left += 64;
        }
        sfClock_restart(fights->control.enemy.clock);
    }
    sfSprite_setTextureRect(fights->control.enemy.sprite,
        fights->control.enemy.rect);
}

void enemies_animation(struct fight_s *fights, unsigned int i)
{
    int tmp = (fights->place.enemies[i].rect.left
        + fights->place.enemies[i].rect.width);
    float sec = sfTime_asSeconds(
        sfClock_getElapsedTime(fights->place.enemies[i].clock));

    if (sec >= 0.28) {
        if (tmp >= 390) {
            fights->place.enemies[i].rect.left = 0;
        } else {
            fights->place.enemies[i].rect.left += 98;
        }
        sfClock_restart(fights->place.enemies[i].clock);
    }
    sfSprite_setTextureRect(fights->place.enemies[i].sprite,
        fights->place.enemies[i].rect);
}

void player_animation(struct fight_s *fights)
{
    float sec = sfTime_asSeconds(
        sfClock_getElapsedTime(fights->player.clock));

    if (sec >= 0.25) {
        if ((fights->player.rect.left + fights->player.rect.width) >= 128) {
            fights->player.rect.left = 0;
        } else {
            fights->player.rect.left += 32;
        }
        sfClock_restart(fights->player.clock);
    }
    sfSprite_setTextureRect(fights->player.sprite, fights->player.rect);
}

/*
** EPITECH PROJECT, 2023
** sprite.c
** File description:
** camera follow player
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "rpg.h"
#include <stdio.h>
#include <unistd.h>

void stop_move(rpg_t *rpg)
{
    if (rpg->sprite.position.x <= rpg->sprite.lower_x) {
        sfSprite_setPosition(rpg->sprite.sprite, (sfVector2f)
            {rpg->sprite.lower_x, rpg->sprite.position.y});
        rpg->sprite.position.x = rpg->sprite.lower_x;
    }
    if (rpg->sprite.position.y <= rpg->sprite.lower_y) {
        sfSprite_setPosition(rpg->sprite.sprite, (sfVector2f)
            {rpg->sprite.position.x, rpg->sprite.lower_y});
        rpg->sprite.position.y = rpg->sprite.lower_y;
    }
    if (rpg->sprite.position.x >= rpg->sprite.upper_x) {
        sfSprite_setPosition(rpg->sprite.sprite, (sfVector2f)
            {rpg->sprite.upper_x, rpg->sprite.position.y});
        rpg->sprite.position.x = rpg->sprite.upper_x;
    }
    if (rpg->sprite.position.y >= rpg->sprite.upper_y) {
        sfSprite_setPosition(rpg->sprite.sprite, (sfVector2f)
            {rpg->sprite.position.x, rpg->sprite.upper_y});
        rpg->sprite.position.y = rpg->sprite.upper_y;
    }
}

void scrolling(rpg_t *rpg)
{
    rpg->sprite.screen_pos.x = rpg->sprite.position.x + 33 -
        (800 / 2);
    rpg->sprite.screen_pos.y = rpg->sprite.position.y + 33 -
        (500 / 2);
    sfView_reset(rpg->view.view, (sfFloatRect) {0,0, 800, 500});
    if (rpg->sprite.screen_pos.x <= rpg->view.lower_x) {
        rpg->sprite.screen_pos.x = rpg->view.lower_x;
    }
    if (rpg->sprite.screen_pos.y <= rpg->view.lower_y) {
        rpg->sprite.screen_pos.y = rpg->view.lower_y;
    }
    if (rpg->sprite.screen_pos.y >= rpg->view.upper_y) {
        rpg->sprite.screen_pos.y = rpg->view.upper_y;
    }
    if (rpg->sprite.screen_pos.x >= rpg->view.upper_x) {
        rpg->sprite.screen_pos.x = rpg->view.upper_x;
    }
    sfView_reset(rpg->view.view, (sfFloatRect) {rpg->sprite.screen_pos.x,
        rpg->sprite.screen_pos.y, 800, 500});
    sfRenderWindow_setView(rpg->window.window, rpg->view.view);
}

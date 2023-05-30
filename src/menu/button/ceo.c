/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** main
*/

#include "rpg.h"
#include <stdio.h>


sfBool is_clicked(rpg_t *rpg, struct my_button *button,
    sfMouseButtonEvent *event)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->rect);
    sfVector2f mouse_pos =
        sfRenderWindow_mapPixelToCoords(rpg->window.window,
            (sfVector2i){event->x, event->y}, NULL);

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)
        && button->state == RELEASED) {
        sfRectangleShape_setFillColor(button->rect,
            button->color.pressed_color);
        button->state = PRESSED;
        return (sfTrue);
    } else if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)
        && button->state == PRESSED) {
        sfRectangleShape_setFillColor(button->rect,
            button->color.color);
        button->state = RELEASED;
        return (sfFalse);
    } else {
        return (sfFalse);
    }
}

sfBool is_hovered(rpg_t *rpg, struct my_button *button,
    sfMouseMoveEvent *event)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(button->rect);
    sfVector2f mouse_pos =
        sfRenderWindow_mapPixelToCoords(rpg->window.window,
            (sfVector2i){event->x, event->y}, NULL);


    if (button->state == RELEASED) {
        if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
            sfRectangleShape_setFillColor(button->rect,
                button->color.hover_color);
            return (sfTrue);
        } else {
            sfRectangleShape_setFillColor(button->rect, button->color.color);
            return (sfFalse);
        }
    } else {
        return (sfFalse);
    }
}

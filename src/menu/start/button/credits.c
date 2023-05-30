/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** credits
*/

#include "rpg.h"

static void start_credits_button_txt(rpg_t *rpg)
{
    rpg->start.txt_menu[3].text = sfText_create();
    sfText_setString(rpg->start.txt_menu[3].text, "CREDITS");
    sfText_setFont(rpg->start.txt_menu[3].text, rpg->font);
    sfText_setCharacterSize(rpg->start.txt_menu[3].text, 40);
    sfText_setPosition(rpg->start.txt_menu[3].text,
        (sfVector2f){170, 675});
}

static void start_credits_button(rpg_t *rpg)
{
    rpg->start.button[3].rect = sfRectangleShape_create();
    rpg->start.button[3].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->start.button[3].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->start.button[3].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->start.button[3].rect,
        (sfVector2f){160, 670});
    sfRectangleShape_setSize(rpg->start.button[3].rect,
        (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->start.button[3].rect,
        rpg->start.button[3].color.color);
    rpg->start.button[3].is_clicked = &is_clicked;
    rpg->start.button[3].is_hover = &is_hovered;
    rpg->start.button[3].state = RELEASED;
}

void init_start_credit(rpg_t *rpg)
{
    start_credits_button_txt(rpg);
    start_credits_button(rpg);
}

void start_credits_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->start.button[3].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->start.txt_menu[3].text, NULL);
}

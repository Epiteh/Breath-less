/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** credits
*/

#include "rpg.h"

static void credits_button_txt(rpg_t *rpg)
{
    rpg->menu.txt_menu[3].text = sfText_create();
    sfText_setString(rpg->menu.txt_menu[3].text, "CREDITS");
    sfText_setFont(rpg->menu.txt_menu[3].text, rpg->font);
    sfText_setCharacterSize(rpg->menu.txt_menu[3].text, 40);
    sfText_setPosition(rpg->menu.txt_menu[3].text,
        (sfVector2f){170, 675});
}

static void credits_button(rpg_t *rpg)
{
    rpg->menu.button[3].rect = sfRectangleShape_create();
    rpg->menu.button[3].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->menu.button[3].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->menu.button[3].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->menu.button[3].rect,
        (sfVector2f){160, 670});
    sfRectangleShape_setSize(rpg->menu.button[3].rect,
        (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->menu.button[3].rect,
        rpg->menu.button[3].color.color);
    rpg->menu.button[3].is_clicked = &is_clicked;
    rpg->menu.button[3].is_hover = &is_hovered;
    rpg->menu.button[3].state = RELEASED;
}

void init_escape_credit(rpg_t *rpg)
{
    credits_button_txt(rpg);
    credits_button(rpg);
}

void escape_credits_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->menu.button[3].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->menu.txt_menu[3].text, NULL);
}

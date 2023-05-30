/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** resume
*/

#include "rpg.h"

static void resume_button_txt(rpg_t *rpg)
{
    rpg->menu.txt_menu[0].text = sfText_create();
    sfText_setString(rpg->menu.txt_menu[0].text, "RESUME");
    sfText_setFont(rpg->menu.txt_menu[0].text, rpg->font);
    sfText_setCharacterSize(rpg->menu.txt_menu[0].text, 40);
    sfText_setPosition(rpg->menu.txt_menu[0].text,
        (sfVector2f){170, 450});
}

static void resume_button(rpg_t *rpg)
{
    rpg->menu.button[0].rect = sfRectangleShape_create();
    rpg->menu.button[0].color.color =
        sfColor_fromRGBA(0, 0, 0, 0);
    rpg->menu.button[0].color.hover_color =
        sfColor_fromRGBA(0, 0, 0, 25);
    rpg->menu.button[0].color.pressed_color =
        sfColor_fromRGBA(0, 0, 0, 50);
    sfRectangleShape_setPosition(rpg->menu.button[0].rect,
        (sfVector2f){160, 445});
    sfRectangleShape_setSize(rpg->menu.button[0].rect,
        (sfVector2f){245, 60});
    sfRectangleShape_setFillColor(rpg->menu.button[0].rect,
        rpg->menu.button[0].color.color);
    rpg->menu.button[0].is_clicked = &is_clicked;
    rpg->menu.button[0].is_hover = &is_hovered;
    rpg->menu.button[0].state = RELEASED;
}

void init_escape_resume(rpg_t *rpg)
{
    resume_button_txt(rpg);
    resume_button(rpg);
}

void escape_resume_view(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->window.window,
        rpg->menu.button[0].rect, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        rpg->menu.txt_menu[0].text, NULL);
}

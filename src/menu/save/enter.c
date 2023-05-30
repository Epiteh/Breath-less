/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** enter
*/

#include "rpg.h"

void enter_text_text(rpg_t *rpg)
{
    rpg->save.txt[0].font = sfFont_createFromFile("assets/Roboto-Light.ttf");
    rpg->save.txt[0].text = sfText_create();
    sfText_setFont(rpg->save.txt[0].text, rpg->save.txt[0].font);
    sfText_setCharacterSize(rpg->save.txt[0].text, 30);
    sfText_setPosition(rpg->save.txt[0].text, (sfVector2f) {750, 527});
    sfText_setColor(rpg->save.txt[0].text, sfBlack);
}

void enter_text(rpg_t *rpg)
{
    rpg->save.input = my_calloc(20, sizeof(char));
    sfText_setString(rpg->save.txt[0].text, rpg->save.input);
}

void display_save_txt(rpg_t *rpg)
{
    sfRenderWindow_drawText(rpg->window.window,
        rpg->save.txt[0].text, NULL);
}

static void cond_enter_text_event(rpg_t *rpg)
{
    if (rpg->window.event.text.unicode == '\b') {
        if (my_strlen(rpg->save.input) > 0)
            rpg->save.input[my_strlen(rpg->save.input) - 1] = '\0';
    } else if (rpg->window.event.text.unicode < 128) {
        rpg->save.input[my_strlen(rpg->save.input)] =
            (char) (rpg->window.event.text.unicode);
    }
}

void enter_text_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtTextEntered) {
        cond_enter_text_event(rpg);
        if (my_strlen(rpg->save.input) <= 16)
            sfText_setString(rpg->save.txt[0].text, rpg->save.input);
    }
}

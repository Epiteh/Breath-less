/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** control
*/

#include "rpg.h"

static void necessities_handler(struct fight_s *fights)
{
    if (fights->control.choices[0].actual == 3)
        fights->control.choices[0].actual = 0;
    if (fights->control.choices[1].actual == 4)
        fights->control.choices[1].actual = 0;
    if (fights->control.choices[2].actual == 3)
        fights->control.choices[2].actual = 0;
    if (fights->control.choices[3].actual == 2)
        fights->control.choices[3].actual = 0;
    if (COCHOICE == 3 && COACTUAL == 0) {
            sfSprite_setRotation(fights->control.choices[0].arrow, 90);
    } else
        sfSprite_setRotation(fights->control.choices[0].arrow, 0);
}

static void draw_texts(rpg_t *rpg, struct fight_s *fights)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        fights->control.choices[0].arrow, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        fights->control.choices[COCHOICE].text[0], NULL);
    if (COCHOICE == 0 || COCHOICE == 1 || COCHOICE == 2 || COCHOICE == 3)
        sfRenderWindow_drawText(rpg->window.window,
            fights->control.choices[COCHOICE].text[1], NULL);
    if (COCHOICE == 1 || COCHOICE == 2)
        sfRenderWindow_drawText(rpg->window.window,
            fights->control.choices[COCHOICE].text[2], NULL);
    if (COCHOICE == 1) {
        sfRenderWindow_drawText(rpg->window.window,
            fights->control.choices[COCHOICE].text[3], NULL);
    }
}

void control_scene(rpg_t *rpg, struct fight_s *fights)
{
    if (fights->player_turn) {
        necessities_handler(fights);
        draw_texts(rpg, fights);
    } else {
        sfSprite_setRotation(fights->control.choices[0].arrow, 90);
        sfRenderWindow_drawSprite(rpg->window.window,
            fights->control.choices[0].arrow, NULL);
        sfRenderWindow_drawText(rpg->window.window,
            fights->control.choices[4].text[0], NULL);
    }
}

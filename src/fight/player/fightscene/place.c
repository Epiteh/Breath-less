/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** place
*/

#include "rpg.h"

static void necessities_handler(struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (fights->place.choices[0].actual == 3)
            fights->place.choices[0].actual = 0;
        if (fights->place.choices[1].actual == 3)
            fights->place.choices[1].actual = 0;
        if (fights->place.choices[2].actual == 3)
            fights->place.choices[2].actual = 0;
        if (PLCHOICE == 3 && PLACTUAL == 0) {
            PLACTUAL = 1;
            tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL];
            sfSprite_setPosition(fights->place.choices[0].arrow, tmp2);
        }
        if (PLCHOICE == 3 && PLACTUAL != 4) {
            sfSprite_setRotation(fights->place.choices[0].arrow, 90);
        } else
            sfSprite_setRotation(fights->place.choices[0].arrow, 0);
}

static void draw_texts(rpg_t *rpg, struct fight_s *fights)
{
    sfRenderWindow_drawSprite(rpg->window.window,
        fights->place.choices[0].arrow, NULL);
    sfRenderWindow_drawText(rpg->window.window,
        fights->place.choices[PLCHOICE].text[0], NULL);
    if (PLCHOICE == 0 || PLCHOICE == 1 || PLCHOICE == 2 || PLCHOICE == 3)
        sfRenderWindow_drawText(rpg->window.window,
            fights->place.choices[PLCHOICE].text[1], NULL);
    if (PLCHOICE == 1 || PLCHOICE == 2)
        sfRenderWindow_drawText(rpg->window.window,
            fights->place.choices[PLCHOICE].text[2], NULL);
}

static void choice_scene_handler(struct fight_s *fights, sfVector2f tmp2)
{
    if (PLCHOICE == 3 && PLACTUAL == 1 && fights->place.enemies[0].datas.dead) {
        PLACTUAL = 2;
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL];
        sfSprite_setPosition(fights->place.choices[0].arrow, tmp2);
    }
    if (PLCHOICE == 3 && PLACTUAL == 2 && fights->place.enemies[1].datas.dead) {
        PLACTUAL = 3;
        tmp2 = fights->place.choices[PLCHOICE].position[PLACTUAL];
        sfSprite_setPosition(fights->place.choices[0].arrow, tmp2);
    }
}

void place_scene(rpg_t *rpg, struct fight_s *fights)
{
    sfVector2f tmp2 = {0, 0};

    if (fights->player_turn) {
        necessities_handler(fights);
        choice_scene_handler(fights, tmp2);
        draw_texts(rpg, fights);
    } else {
        sfSprite_setRotation(fights->place.choices[0].arrow, 90);
        sfRenderWindow_drawSprite(rpg->window.window,
            fights->place.choices[0].arrow, NULL);
        sfRenderWindow_drawText(rpg->window.window,
            fights->place.choices[4].text[0], NULL);
    }
}

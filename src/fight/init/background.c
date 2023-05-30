/*
** EPITECH PROJECT, 2023
** Epiteh-Engine
** File description:
** values
*/

#include "rpg.h"
#include <stdlib.h>

void display_fight_background(rpg_t *rpg)
{
    if (rpg->fights.place.fight) {
        sfRenderWindow_drawSprite(rpg->window.window,
            rpg->fights.bg[0].sprite, NULL);
    }
    if (rpg->fights.control.fight) {
        sfRenderWindow_drawSprite(rpg->window.window,
            rpg->fights.bg[1].sprite, NULL);
    }
}

void init_fight_background(rpg_t *rpg)
{
    rpg->fights.bg = my_calloc(2, sizeof(*rpg->fights.bg));
    rpg->fights.bg[0].texture =
        sfTexture_createFromFile("assets/first_fight_menu.png", NULL);
    rpg->fights.bg[0].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->fights.bg[0].sprite,
        rpg->fights.bg[0].texture, sfTrue);
    sfSprite_setScale(rpg->fights.bg[0].sprite, (sfVector2f){1, 0.95});
    sfSprite_setPosition(rpg->fights.bg[0].sprite, (sfVector2f){0, 0});
    rpg->fights.bg[1].texture =
        sfTexture_createFromFile("assets/fightscene.png", NULL);
    rpg->fights.bg[1].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->fights.bg[1].sprite,
        rpg->fights.bg[1].texture, sfTrue);
    sfSprite_setScale(rpg->fights.bg[1].sprite, (sfVector2f){1, 0.95});
    sfSprite_setPosition(rpg->fights.bg[1].sprite, (sfVector2f){0, 0});
}

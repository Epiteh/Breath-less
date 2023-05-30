/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** txt
*/

#include "rpg.h"

void init_start_game_creator(rpg_t *rpg)
{
    rpg->creator.sprite[5].texture =
        sfTexture_createFromFile("assets/menu/char/rect.png", NULL);
    rpg->creator.sprite[5].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->creator.sprite[5].sprite,
        rpg->creator.sprite[5].texture, sfTrue);
    sfSprite_setPosition(rpg->creator.sprite[5].sprite,
        (sfVector2f){827, 714});
}

void init_start_game_creator_hover(rpg_t *rpg)
{
    rpg->creator.sprite[6].texture =
        sfTexture_createFromFile("assets/menu/char/rect_hover.png", NULL);
    rpg->creator.sprite[6].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->creator.sprite[6].sprite,
        rpg->creator.sprite[6].texture, sfTrue);
    sfSprite_setPosition(rpg->creator.sprite[6].sprite,
        (sfVector2f){827, 714});
}

void init_start_game_creator_txt(rpg_t *rpg)
{
    rpg->creator.sprite[7].texture =
        sfTexture_createFromFile("assets/menu/char/start_txt.png", NULL);
    rpg->creator.sprite[7].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->creator.sprite[7].sprite,
        rpg->creator.sprite[7].texture, sfTrue);
    sfSprite_setPosition(rpg->creator.sprite[7].sprite,
        (sfVector2f){827, 714});
}

/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** init
*/

#include "rpg.h"

static void init_first_loader_image(rpg_t *rpg)
{
    rpg->loader.sprite[0].texture =
        sfTexture_createFromFile("assets/loader/4.png", NULL);
    rpg->loader.sprite[0].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->loader.sprite[0].sprite,
        rpg->loader.sprite[0].texture, sfTrue);
    sfSprite_setScale(rpg->loader.sprite[0].sprite,
        (sfVector2f){1.01, 0.95});
}

static void init_second_loader_image(rpg_t *rpg)
{
    rpg->loader.sprite[1].texture =
        sfTexture_createFromFile("assets/loader/3.png", NULL);
    rpg->loader.sprite[1].sprite = sfSprite_create();
    sfSprite_setTexture(rpg->loader.sprite[1].sprite,
        rpg->loader.sprite[1].texture, sfTrue);
    sfSprite_setScale(rpg->loader.sprite[1].sprite,
        (sfVector2f){1.01, 0.95});
}

void init_loader_image(rpg_t *rpg)
{
    init_first_loader_image(rpg);
    init_second_loader_image(rpg);
}

/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** sprite
*/

#include "rpg.h"

void init_choice_sprite(rpg_t *rpg)
{
    rpg->creator.rect_size = (sfIntRect){0, 0, 32, 32};
    rpg->creator.index = 3;
    rpg->creator.sprite[3].sprite = sfSprite_create();
    rpg->creator.sprite[3].texture =
        sfTexture_createFromFile("assets/menu/char/river.png", NULL);
    sfSprite_setTexture(rpg->creator.sprite[3].sprite,
        rpg->creator.sprite[3].texture, sfTrue);
    sfSprite_setTextureRect(rpg->creator.sprite[3].sprite,
        rpg->creator.rect_size);
    sfSprite_setPosition(rpg->creator.sprite[3].sprite,
        (sfVector2f){400, 430});
    sfSprite_setScale(rpg->creator.sprite[3].sprite,
        (sfVector2f){5, 5});
}

void init_second_choice_sprite(rpg_t *rpg)
{
    rpg->creator.sprite[4].sprite = sfSprite_create();
    rpg->creator.sprite[4].texture =
        sfTexture_createFromFile("assets/menu/char/lucy.png", NULL);
    sfSprite_setTexture(rpg->creator.sprite[4].sprite,
        rpg->creator.sprite[4].texture, sfTrue);
    sfSprite_setTextureRect(rpg->creator.sprite[4].sprite,
        rpg->creator.rect_size);
    sfSprite_setPosition(rpg->creator.sprite[4].sprite,
        (sfVector2f){400, 430});
    sfSprite_setScale(rpg->creator.sprite[4].sprite,
        (sfVector2f){5, 5});
}

void choice_sprite_view(rpg_t *rpg)
{
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(rpg->clock.clock));

    if (sec >= 0.3) {
        if ((rpg->creator.rect_size.left +
            rpg->creator.rect_size.width) >= 128) {
                rpg->creator.rect_size.left = 0;
        } else {
            rpg->creator.rect_size.left += 32;
        }
        sfClock_restart(rpg->clock.clock);
    }
    sfSprite_setTextureRect(rpg->creator.sprite[rpg->creator.index].sprite,
        rpg->creator.rect_size);
    sfRenderWindow_drawSprite(rpg->window.window,
        rpg->creator.sprite[rpg->creator.index].sprite, NULL);
}

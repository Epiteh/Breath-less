/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** fade
*/

#include "rpg.h"

void init_loader_fade_rect(rpg_t *rpg)
{
    rpg->loader.rect[0].rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->loader.rect[0].rect,
        (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(rpg->loader.rect[0].rect,
        (sfColor){0, 0, 0, 0});
}

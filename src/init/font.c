/*
** EPITECH PROJECT, 2023
** Collectible
** File description:
** font.c
*/

#include "rpg.h"

int init_font(rpg_t *rpg)
{
    rpg->font =
        sfFont_createFromFile("assets/fonts/Roboto-Light.ttf");
    if (!rpg->font)
        return (84);
    return (0);
}

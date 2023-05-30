/*
** EPITECH PROJECT, 2023
** RPG_MISSION
** File description:
** font.c
*/

#include "rpg.h"

void destroy_font(rpg_t *rpg)
{
    sfFont_destroy(rpg->font);
}

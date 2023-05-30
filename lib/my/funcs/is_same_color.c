/*
** EPITECH PROJECT, 2023
** TP_RPG
** File description:
** collision.c
*/
#include "../../../include/rpg.h"

bool is_same_color(sfColor color, sfColor targeted_color)
{
    if (color.r == targeted_color.r && color.g == targeted_color.g &&
        color.b == targeted_color.b && color.a == targeted_color.a) {
        return (true);
    }
    return (false);
}

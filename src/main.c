/*
** EPITECH PROJECT, 2023
** Epiteh-Engine
** File description:
** main
*/

#include "rpg.h"

struct my_scene scene = {
    .scene = "start",
};

int main(void)
{
    rpg_t rpg;

    main_game_loop(&rpg);
    return (0);
}

/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** values
*/

#include "rpg.h"
#include "stdbool.h"

static void init_char_bg_menu(rpg_t *rpg)
{
    rpg->creator.sprite[0].sprite = sfSprite_create();
    rpg->creator.sprite[0].texture =
        sfTexture_createFromFile("assets/menu/char/background.png", NULL);
    sfSprite_setTexture(rpg->creator.sprite[0].sprite,
        rpg->creator.sprite[0].texture, sfTrue);
    sfSprite_setPosition(rpg->creator.sprite[0].sprite,
        (sfVector2f){0, -15});
}

static void init_char_buttons(rpg_t *rpg)
{
    init_char_bg_menu(rpg);
    init_right_player(rpg);
    init_left_player(rpg);
    init_choice_sprite(rpg);
    init_second_choice_sprite(rpg);
    speed_creator_button(rpg);
    strength_creator_button(rpg);
    intelligence_creator_button(rpg);
    init_start_game_creator(rpg);
    init_start_game_creator_hover(rpg);
    init_start_game_creator_txt(rpg);
}

static void init_char_struct(rpg_t *rpg)
{
    rpg->creator.is_hover = false;
    rpg->creator.skills = 7;
    rpg->creator.sprite = my_calloc(8, sizeof(struct sprite_char));
    rpg->creator.button = my_calloc(15, sizeof(struct my_button));
}

void init_char_values(rpg_t *rpg)
{
    init_char_struct(rpg);
    init_char_buttons(rpg);
}

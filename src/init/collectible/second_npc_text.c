/*
** EPITECH PROJECT, 2023
** Collectible
** File description:
** second_npc_text.c
*/

#include "rpg.h"

char *load_message_content_safe_place(void)
{
    char *str = my_strdup("Watchu doing tonight ?");

    return (str);
}

void load_safe_place_message(rpg_t *rpg)
{
    rpg->collectible.safe_place_npc.letter_counter = 0;
    rpg->collectible.safe_place_npc.message_content =
    load_message_content_safe_place();
    rpg->collectible.safe_place_npc.message = sfText_create();
    sfText_setFont(rpg->collectible.safe_place_npc.message, rpg->font);
    sfText_setCharacterSize(rpg->collectible.safe_place_npc.message, 12);
    sfText_setFillColor(rpg->collectible.safe_place_npc.message, sfWhite);
    sfText_setPosition(rpg->collectible.safe_place_npc.message,
        (sfVector2f) {50, 310});
    rpg->collectible.safe_place_npc.text_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->collectible.safe_place_npc.text_rect,
        (sfVector2f) {10, 300});
    sfRectangleShape_setSize(rpg->collectible.safe_place_npc.text_rect,
        (sfVector2f){200, 35});
    sfRectangleShape_setFillColor(rpg->collectible.safe_place_npc.text_rect,
        sfColor_fromRGBA(0, 0, 0, 200));
}

char *load_message_content_back_safe_place_message(void)
{
    char *str = my_strdup("We saw everything you\'ve done,\n we wanna help"
    " you");
    return (str);
}

void load_back_safe_place_message(rpg_t *rpg)
{
    rpg->collectible.back_safe_place_npc.message_content =
    load_message_content_back_safe_place_message();
    rpg->collectible.back_safe_place_npc.letter_counter = 0;
    rpg->collectible.back_safe_place_npc.message = sfText_create();
    sfText_setFont(rpg->collectible.back_safe_place_npc.message, rpg->font);
    sfText_setCharacterSize(rpg->collectible.back_safe_place_npc.message, 12);
    sfText_setFillColor(rpg->collectible.back_safe_place_npc.message, sfWhite);
    sfText_setPosition(rpg->collectible.back_safe_place_npc.message,
        (sfVector2f) {254 - 40, 2065});
    rpg->collectible.back_safe_place_npc.text_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->collectible.back_safe_place_npc.text_rect,
        (sfVector2f) {254 - 60, 2050 + 10});
    sfRectangleShape_setSize(rpg->collectible.back_safe_place_npc.text_rect,
        (sfVector2f){200, 38});
    sfRectangleShape_setFillColor(rpg->collectible.
        back_safe_place_npc.text_rect, sfColor_fromRGBA(0, 0, 0, 200));
}

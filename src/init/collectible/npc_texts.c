/*
** EPITECH PROJECT, 2023
** Collectible
** File description:
** npc_texts.c
*/

#include "rpg.h"

char *load_message_content_map_place(void)
{
    char *str = my_strdup("Bzzz, non-authorized human\nwalking, "
        "engaging protocol...");

    return (str);
}

void load_map_place_message(rpg_t *rpg)
{
    rpg->collectible.main_place_npc.message_content =
    load_message_content_map_place();
    rpg->collectible.main_place_npc.message = sfText_create();
    sfText_setFont(rpg->collectible.main_place_npc.message, rpg->font);
    sfText_setCharacterSize(rpg->collectible.main_place_npc.message, 12);
    sfText_setFillColor(rpg->collectible.main_place_npc.message, sfWhite);
    sfText_setPosition(rpg->collectible.main_place_npc.message,
        (sfVector2f) {635 - 5, 1417});
    rpg->collectible.main_place_npc.text_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->collectible.main_place_npc.text_rect,
        (sfVector2f) {635 - 30, 1410});
    sfRectangleShape_setSize(rpg->collectible.main_place_npc.text_rect,
        (sfVector2f){200, 45});
    sfRectangleShape_setFillColor(rpg->collectible.main_place_npc.text_rect,
        sfColor_fromRGBA(0, 0, 0, 200));
}

static char *load_message_content_bar(void)
{
    char *str = my_strdup("Tell me if you need anything.");

    return (str);
}

void load_bar_message(rpg_t *rpg)
{
    rpg->collectible.bar_npc.message_content =
    load_message_content_bar();
    rpg->collectible.bar_npc.message = sfText_create();
    sfText_setFont(rpg->collectible.bar_npc.message, rpg->font);
    sfText_setCharacterSize(rpg->collectible.bar_npc.message, 12);
    sfText_setFillColor(rpg->collectible.bar_npc.message, sfWhite);
    sfText_setPosition(rpg->collectible.bar_npc.message,
        (sfVector2f) {65, 785});
    rpg->collectible.bar_npc.text_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->collectible.bar_npc.text_rect,
        (sfVector2f) {70 - 30, 785 - 5});
    sfRectangleShape_setSize(rpg->collectible.bar_npc.text_rect,
        (sfVector2f){200, 25});
    sfRectangleShape_setFillColor(rpg->collectible.bar_npc.text_rect,
        sfColor_fromRGBA(0, 0, 0, 200));
}

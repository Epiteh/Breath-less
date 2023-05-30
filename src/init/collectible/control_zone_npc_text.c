/*
** EPITECH PROJECT, 2023
** Collectible
** File description:
** control_zone_npc_text.c
*/

#include "rpg.h"

char *load_message_content_control_zone(void)
{
    char *str = my_strdup("Bzz, non-authorized human detected\nin a"
        " non-authorized building\nengaging ETOS protocol"
        "...");
    return (str);
}

void load_control_zone_message(rpg_t *rpg)
{
    rpg->collectible.control_zone_npc.message_content =
    load_message_content_control_zone();
    rpg->collectible.control_zone_npc.message = sfText_create();
    sfText_setFont(rpg->collectible.control_zone_npc.message, rpg->font);
    sfText_setCharacterSize(rpg->collectible.control_zone_npc.message, 12);
    sfText_setFillColor(rpg->collectible.control_zone_npc.message, sfWhite);
    sfText_setPosition(rpg->collectible.control_zone_npc.message,
        (sfVector2f) {1060, 435});
    rpg->collectible.control_zone_npc.text_rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->collectible.control_zone_npc.text_rect,
        (sfVector2f) {1051, 425});
    sfRectangleShape_setSize(rpg->collectible.control_zone_npc.text_rect,
        (sfVector2f){210, 60});
    sfRectangleShape_setFillColor(rpg->collectible.control_zone_npc.text_rect,
        sfColor_fromRGBA(0, 0, 0, 200));
}

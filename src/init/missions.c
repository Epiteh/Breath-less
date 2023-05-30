/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** missions.C
*/
#include "rpg.h"

static void init_rectangle(rpg_t *rpg)
{
    rpg->mission_text.large_sprite = sfSprite_create();
    rpg->mission_text.large_texture = sfTexture_createFromFile(
        "assets/missions/large.png", NULL);
    sfSprite_setTexture(rpg->mission_text.large_sprite,
        rpg->mission_text.large_texture, sfTrue);
    sfSprite_setPosition(rpg->mission_text.large_sprite,
        (sfVector2f) {1525, 410});

    rpg->mission_text.small_sprite = sfSprite_create();
    rpg->mission_text.small_texture = sfTexture_createFromFile(
        "assets/missions/small.png", NULL);
    sfSprite_setTexture(rpg->mission_text.small_sprite,
        rpg->mission_text.small_texture, sfTrue);
    sfSprite_setPosition(rpg->mission_text.small_sprite,
        (sfVector2f) {1525, 412});
}

void init_advancement(rpg_t *rpg)
{
    rpg->mission.escape_bar_done = false;
    rpg->mission.catch_knife_done = false;
    rpg->mission.go_place_done = false;
    rpg->mission.go_safe_place_done = false;
    rpg->mission.do_place_fight_done = false;
    rpg->mission.go_control_zone_done = false;
    rpg->mission.do_control_fight = false;
    rpg->mission.go_back_safe_place_done = false;
    rpg->mission.do_control_fight_done = false;
    rpg->mission.escape_bar = false;
    rpg->mission.catch_knife = false;
    rpg->mission.go_place = false;
    rpg->mission.go_safe_place = false;
    rpg->mission.do_place_fight = false;
    rpg->mission.go_control_zone = false;
    rpg->mission.do_control_fight = false;
    rpg->mission.go_back_safe_place = false;
}

static void init_text(rpg_t *rpg)
{
    rpg->mission_text.text = sfText_create();
    sfText_setFont(rpg->mission_text.text, rpg->font);
    sfText_setCharacterSize(rpg->mission_text.text, 20);
    sfText_setColor(rpg->mission_text.text, sfWhite);
    sfText_setPosition(rpg->mission_text.text,
        (sfVector2f) {1525 + 50, 410 + 13});
    rpg->mission_text.letter_counter = 0;
    rpg->mission_text.is_writing = true;
}

void init_mission(rpg_t *rpg)
{
    init_rectangle(rpg);
    init_text(rpg);
    init_advancement(rpg);
    rpg->mission_text.clock = sfClock_create();
}

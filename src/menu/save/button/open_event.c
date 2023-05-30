/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** open_event
*/

#include "rpg.h"
#include <stdio.h>

static void fill_another_other_struct(rpg_t *rpg)
{
    rpg->mission.escape_bar = rpg->save.info.escape_bar;
    rpg->mission.catch_knife = rpg->save.info.catch_knife;
    rpg->mission.go_place = rpg->save.info.go_place;
    rpg->mission.go_safe_place = rpg->save.info.go_safe_place;
    rpg->mission.do_place_fight = rpg->save.info.do_place_fight;
    rpg->mission.go_control_zone = rpg->save.info.go_control_zone;
    rpg->mission.do_control_fight = rpg->save.info.do_control_fight;
    rpg->mission.go_back_safe_place = rpg->save.info.go_back_safe_place;
}

static void fill_other_struct(rpg_t *rpg)
{
    rpg->mission.escape_bar_done = rpg->save.info.escape_bar_done;
    rpg->mission.catch_knife_done = rpg->save.info.catch_knife_done;
    rpg->mission.go_place_done = rpg->save.info.go_place_done;
    rpg->mission.go_safe_place_done = rpg->save.info.go_safe_place_done;
    rpg->mission.do_place_fight_done = rpg->save.info.do_place_fight_done;
    rpg->mission.go_control_zone_done = rpg->save.info.go_control_zone_done;
    rpg->mission.do_control_fight_done = rpg->save.info.do_control_fight_done;
    rpg->mission.go_back_safe_place_done =
        rpg->save.info.go_back_safe_place_done;
    rpg->fights.player.datas.level = rpg->save.info.level;
    rpg->fights.player.datas.xp = rpg->save.info.xp;
    rpg->fights.player.datas.hp = rpg->save.info.hp;
    rpg->sprite.position.x = rpg->save.info.pos_x;
    rpg->sprite.position.y = rpg->save.info.pos_y;
    scene.scene = my_strdup(rpg->save.info.scene);
    fill_another_other_struct(rpg);
}

struct save_info load_file_event(rpg_t *rpg)
{
    FILE *file = NULL;

    file = fopen(rpg->save.input, "rb");
    if (!file)
        return (rpg->save.info);
    fread(&rpg->save.info, sizeof(struct save_info), 1, file);
    fclose(file);
    return (rpg->save.info);
}

static void do_cond_open_button_event(rpg_t *rpg)
{
    if (rpg->save.button[1].state == PRESSED) {
        sfRenderWindow_setVisible(rpg->window.window, sfFalse);
        rpg->save.info = load_file_event(rpg);
        fill_other_struct(rpg);
        printf("Level: %d\n", rpg->save.info.level);
        rpg->save.is_load = false;
        sfRenderWindow_setVisible(rpg->window.window, sfTrue);
    }
}

void open_button_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->save.button[1].is_clicked(rpg, &rpg->save.button[1],
            &rpg->window.event.mouseButton)) {
                do_cond_open_button_event(rpg);
                rpg->save.button[1].state = RELEASED;
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->save.button[1].is_hover(rpg, &rpg->save.button[1],
            &rpg->window.event.mouseMove);
    }
}

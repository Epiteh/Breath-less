/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** ceo
*/

#include "rpg.h"
#include <stdbool.h>
#include <stdio.h>

static void fill_another_struct_save(rpg_t *rpg)
{
    rpg->save.info.escape_bar = rpg->mission.escape_bar;
    rpg->save.info.catch_knife = rpg->mission.catch_knife;
    rpg->save.info.go_place = rpg->mission.go_place;
    rpg->save.info.go_safe_place = rpg->mission.go_safe_place;
    rpg->save.info.do_place_fight = rpg->mission.do_place_fight;
    rpg->save.info.go_control_zone = rpg->mission.go_control_zone;
    rpg->save.info.do_control_fight = rpg->mission.do_control_fight;
    rpg->save.info.go_back_safe_place = rpg->mission.go_back_safe_place;
    rpg->save.info.xp = rpg->fights.player.datas.xp;
    rpg->save.info.hp = rpg->fights.player.datas.hp;
}

static void fill_struct_save(rpg_t *rpg)
{
    rpg->save.info.escape_bar_done = rpg->mission.escape_bar_done;
    rpg->save.info.catch_knife_done = rpg->mission.catch_knife_done;
    rpg->save.info.go_place_done = rpg->mission.go_place_done;
    rpg->save.info.go_safe_place_done = rpg->mission.go_safe_place_done;
    rpg->save.info.do_place_fight_done = rpg->mission.do_place_fight_done;
    rpg->save.info.go_control_zone_done = rpg->mission.go_control_zone_done;
    rpg->save.info.do_control_fight_done = rpg->mission.do_control_fight_done;
    rpg->save.info.go_back_safe_place_done =
        rpg->mission.go_back_safe_place_done;
    rpg->save.info.level = rpg->fights.player.datas.level;
    rpg->save.info.pos_x = rpg->sprite.position.x;
    rpg->save.info.pos_y = rpg->sprite.position.y;
    int y = my_strlen(scene.scene);
    for (int i = 0; i <= y; i++)
        rpg->save.info.scene[i] = scene.scene[i];
    fill_another_struct_save(rpg);
}

static void save_file_event(rpg_t *rpg)
{
    FILE *file = NULL;

    file = fopen(rpg->save.input, "wb");
    if (!file)
        return;
    fwrite(&rpg->save.info, sizeof(struct save_info), 1, file);
    fclose(file);
}

static void do_cond_save_button_event(rpg_t *rpg)
{
    if (rpg->save.button[0].state == PRESSED) {
        fill_struct_save(rpg);
        printf("Level : %d\n", rpg->fights.player.datas.level);
        printf("SCENE INFO: %s\n", rpg->save.info.scene);
        fflush(stdout);
        save_file_event(rpg);
    }
    rpg->save.button[0].state = RELEASED;
    rpg->save.is_save = false;
}

void save_button_event(rpg_t *rpg)
{
    if (rpg->window.event.type == sfEvtMouseButtonPressed) {
        if (rpg->save.button[0].is_clicked(rpg, &rpg->save.button[0],
            &rpg->window.event.mouseButton)) {
                do_cond_save_button_event(rpg);
            }
    }
    if (rpg->window.event.type == sfEvtMouseMoved) {
        rpg->save.button[0].is_hover(rpg, &rpg->save.button[0],
            &rpg->window.event.mouseMove);
    }
}

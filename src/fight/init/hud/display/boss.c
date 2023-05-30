/*
** EPITECH PROJECT, 2023
** move_view
** File description:
** boss
*/

#include "rpg.h"

static int check_over_640(struct fight_s *fights, char *str, char *path)
{
    if (fights->control.enemy.datas.hp < 850
        && fights->control.enemy.datas.hp > 700) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->control.enemy.datas.hp, 5, str);
        path = my_strdup("assets/bars_states/full-1.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    if (fights->control.enemy.datas.hp < 700
        && fights->control.enemy.datas.hp > 640) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->control.enemy.datas.hp, 5, str);
        path = my_strdup("assets/bars_states/full-3.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    return (0);
}

static int check_over_425(struct fight_s *fights, char *str, char *path)
{
    if (check_over_640(fights, str, path) == 1)
        return (1);
    if (fights->control.enemy.datas.hp < 640
        && fights->control.enemy.datas.hp > 500) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->control.enemy.datas.hp, 5, str);
        path = my_strdup("assets/bars_states/full-4.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    if (fights->control.enemy.datas.hp < 500
        && fights->control.enemy.datas.hp > 425) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->control.enemy.datas.hp, 5, str);
        path = my_strdup("assets/bars_states/full-5.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    return (0);
}

static int check_over_240(struct fight_s *fights, char *str, char *path)
{
    if (fights->control.enemy.datas.hp < 425
        && fights->control.enemy.datas.hp > 300) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->control.enemy.datas.hp, 5, str);
        path = my_strdup("assets/bars_states/full-6.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    if (fights->control.enemy.datas.hp < 300
        && fights->control.enemy.datas.hp > 240) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->control.enemy.datas.hp, 5, str);
        path = my_strdup("assets/bars_states/full-7.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    return (0);
}

static int check_under_425(struct fight_s *fights, char *str, char *path)
{
    if (check_over_240(fights, str, path) == 1)
        return (1);
    if (fights->control.enemy.datas.hp < 240
        && fights->control.enemy.datas.hp > 100) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->control.enemy.datas.hp, 5, str);
        path = my_strdup("assets/bars_states/full-8.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    if (fights->control.enemy.datas.hp < 100
        && fights->control.enemy.datas.hp > 0) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->control.enemy.datas.hp, 5, str);
        path = my_strdup("assets/bars_states/full-9.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    return (0);
}

void check_boss_datas(struct fight_s *fights)
{
    char *str = my_calloc(4, sizeof(char));
    char *path = NULL;

    if (fights->control.enemy.datas.hp == 850) {
        sfText_setString(fights->place.hud[5].text, "850/850");
        path = my_strdup("assets/bars_states/full.png");
        replace_cotexture(fights, 5, path);
        return;
    }
    if (check_over_425(fights, str, path) == 1
        || check_under_425(fights, str, path) == 1)
        return;
    if (fights->control.enemy.datas.hp <= 0) {
        sfText_setString(fights->place.hud[5].text, "0/850");
        path = my_strdup("assets/bars_states/end.png");
        replace_cotexture(fights, 5, path);
        return;
    }
}

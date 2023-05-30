/*
** EPITECH PROJECT, 2023
** move_view
** File description:
** life
*/

#include "rpg.h"

static int check_over_640(struct fight_s *fights, int idx, char *str,
    char *path)
{
    if (fights->player.datas.hp < 850 && fights->player.datas.hp > 700) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-1.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    if (fights->player.datas.hp < 700 && fights->player.datas.hp > 640) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-3.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    return (0);
}

static int check_over_425(struct fight_s *fights, int idx, char *str,
    char *path)
{
    if (check_over_640(fights, idx, str, path) == 1)
        return (1);
    if (fights->player.datas.hp < 640 && fights->player.datas.hp > 500) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-4.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    if (fights->player.datas.hp < 500 && fights->player.datas.hp > 425) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-5.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    return (0);
}

static int check_over_240(struct fight_s *fights, int idx, char *str,
    char *path)
{
    if (fights->player.datas.hp < 425 && fights->player.datas.hp > 300) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-6.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    if (fights->player.datas.hp < 300 && fights->player.datas.hp > 240) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-7.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    return (0);
}

static int check_under_425(struct fight_s *fights, int idx, char *str,
    char *path)
{
    if (check_over_240(fights, idx, str, path) == 1)
        return (1);
    if (fights->player.datas.hp < 240 && fights->player.datas.hp > 100) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-8.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    if (fights->player.datas.hp < 100 && fights->player.datas.hp > 0) {
        fights->tmp = my_strdup("/850");
        replace_costr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-9.png");
        replace_cotexture(fights, 5, path);
        return (1);
    }
    return (0);
}

void cocheck_life(struct fight_s *fights, int idx)
{
    char *str = my_calloc(4, sizeof(char));
    char *path = NULL;

    if (fights->player.datas.hp == 200) {
        sfText_setString(fights->place.hud[idx].text, "200/200");
        path = my_strdup("assets/bars_states/full.png");
        replace_cotexture(fights, idx, path);
        return;
    }
    if (check_over_425(fights, idx, str, path) == 1
        || check_under_425(fights, idx, str, path) == 1)
        return;
    if (fights->player.datas.hp <= 0) {
        sfText_setString(fights->place.hud[idx].text, "0/200");
        path = my_strdup("assets/bars_states/end.png");
        replace_cotexture(fights, idx, path);
        return;
    }
}

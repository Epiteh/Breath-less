/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** life
*/

#include "rpg.h"

static int check_over_150(struct fight_s *fights, int idx)
{
    char *str = my_calloc(4, sizeof(char));
    char *path = NULL;

    if (fights->player.datas.hp < 200 && fights->player.datas.hp > 175) {
        fights->tmp = my_strdup("/200");
        replace_plstr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-1.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    if (fights->player.datas.hp < 175 && fights->player.datas.hp > 150) {
        fights->tmp = my_strdup("/200");
        replace_plstr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-3.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    return (0);
}

static int check_over_100(struct fight_s *fights, int idx)
{
    char *str = my_calloc(4, sizeof(char));
    char *path = NULL;

    if (check_over_150(fights, idx) == 1)
        return (1);
    if (fights->player.datas.hp < 150 && fights->player.datas.hp > 125) {
        fights->tmp = my_strdup("/200");
        replace_plstr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-4.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    if (fights->player.datas.hp < 125 && fights->player.datas.hp > 100) {
        fights->tmp = my_strdup("/200");
        replace_plstr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-5.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    return (0);
}

static int check_over_50(struct fight_s *fights, int idx)
{
    char *str = my_calloc(4, sizeof(char));
    char *path = NULL;

    if (fights->player.datas.hp < 100 && fights->player.datas.hp > 75) {
        fights->tmp = my_strdup("/200");
        replace_plstr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-6.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    if (fights->player.datas.hp < 75 && fights->player.datas.hp > 50) {
        fights->tmp = my_strdup("/200");
        replace_plstr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-7.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    return (0);
}

static int check_under_50(struct fight_s *fights, int idx)
{
    char *str = my_calloc(4, sizeof(char));
    char *path = NULL;

    if (check_over_50(fights, idx) == 1)
        return (1);
    if (fights->player.datas.hp < 50 && fights->player.datas.hp > 25) {
        fights->tmp = my_strdup("/200");
        replace_plstr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-8.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    if (fights->player.datas.hp < 25 && fights->player.datas.hp > 0) {
        fights->tmp = my_strdup("/200");
        replace_plstr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-9.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    return (0);
}

void plcheck_life(struct fight_s *fights, int idx)
{
    char *path = NULL;

    if (fights->player.datas.hp == 200) {
        sfText_setString(fights->place.hud[idx].text, "200/200");
        path = my_strdup("assets/bars_states/full.png");
        replace_pltexture(fights, idx, path);
        return;
    }
    if (check_over_100(fights, idx) == 1 || check_under_50(fights, idx))
        return;
    if (fights->player.datas.hp <= 0) {
        sfText_setString(fights->place.hud[idx].text, "0/200");
        path = my_strdup("assets/bars_states/end.png");
        replace_pltexture(fights, idx, path);
        return;
    }
}

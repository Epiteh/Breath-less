/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** enemies
*/

#include "rpg.h"

static int check_over_50(struct fight_s *fights, int idx, int tmp, char *str)
{
    char *path = NULL;

    if (tmp < 100 && tmp > 75) {
        fights->tmp = my_strdup("/100");
        replace_plstr(fights, tmp, idx, str);
        path = my_strdup("assets/bars_states/full-2.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    if (tmp < 75 && tmp > 50) {
        fights->tmp = my_strdup("/100");
        replace_plstr(fights, tmp, idx, str);
        path = my_strdup("assets/bars_states/full-4.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    return (0);
}

static int check_under_50(struct fight_s *fights, int idx, int tmp, char *str)
{
    char *path = NULL;

    if (tmp < 50 && tmp > 25) {
        fights->tmp = my_strdup("/100");
        replace_plstr(fights, tmp, idx, str);
        path = my_strdup("assets/bars_states/full-6.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    if (tmp < 25 && tmp > 0) {
        fights->tmp = my_strdup("/100");
        replace_plstr(fights, tmp, idx, str);
        path = my_strdup("assets/bars_states/full-8.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    return (0);
}

static int check_death(struct fight_s *fights, int idx, int tmp)
{
    char *path = NULL;

    if (tmp <= 0) {
        sfText_setString(fights->place.hud[idx].text, "0/100");
        path = my_strdup("assets/bars_states/end.png");
        replace_pltexture(fights, idx, path);
        return (1);
    }
    return (0);
}

void check_enemies_datas(struct fight_s *fights, int idx)
{
    int tmp = fights->place.enemies[idx - 5].datas.hp;
    char *str = my_calloc(4, sizeof(char));
    char *path = NULL;

    if (tmp == 100) {
        sfText_setString(fights->place.hud[idx].text, "100/100");
        path = my_strdup("assets/bars_states/full.png");
        replace_pltexture(fights, idx, path);
        return;
    }
    if (check_over_50(fights, idx, tmp, str) == 1
        || check_under_50(fights, idx, tmp, str) == 1
            || check_death(fights, idx, tmp) == 1)
        return;
}

/*
** EPITECH PROJECT, 2023
** move_view
** File description:
** mind
*/

#include "rpg.h"

static int check_over_50(struct fight_s *fights, int idx, char *str)
{
    int tmp = fights->player.datas.mindfulness;
    char *path = NULL;

    if (tmp < 100 && tmp > 75) {
        fights->tmp = my_strdup("/100");
        replace_costr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-2.png");
        replace_cotexture(fights, idx, path);
        return (1);
    }
    if (tmp < 75 && tmp > 50) {
        fights->tmp = my_strdup("/100");
        replace_costr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-4.png");
        replace_cotexture(fights, idx, path);
        return (1);
    }
    return (0);
}

static void check_under_50(struct fight_s *fights, int idx, char *str)
{
    int tmp = fights->player.datas.mindfulness;
    char *path = NULL;

    if (tmp < 50 && tmp > 25) {
        fights->tmp = my_strdup("/100");
        replace_costr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-6.png");
        replace_cotexture(fights, idx, path);
        return;
    }
    if (tmp < 25 && tmp > 0) {
        fights->tmp = my_strdup("/100");
        replace_costr(fights, fights->player.datas.hp, idx, str);
        path = my_strdup("assets/bars_states/full-8.png");
        replace_cotexture(fights, idx, path);
        return;
    }
}

void cocheck_mind(struct fight_s *fights, int idx)
{
    char *str = my_calloc(4, sizeof(char));
    char *path = NULL;

    if (fights->player.datas.mindfulness == 100) {
        sfText_setString(fights->control.hud[idx].text, "100/100");
        path = my_strdup("assets/bars_states/full.png");
        replace_cotexture(fights, idx, path);
        return;
    }
    if (check_over_50(fights, idx, str) == 1)
        return;
    check_under_50(fights, idx, str);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** life
*/

#include "rpg.h"

static void set_text(struct fight_s *fights, sfVector2f *text_pos, int i)
{
    fights->place.hud[i].text = sfText_create();
    sfText_setString(fights->place.hud[i].text, "100/100");
    sfText_setFont(fights->place.hud[i].text,
        fights->place.choices[0].font);
    sfText_setCharacterSize(fights->place.hud[i].text, 18);
    sfText_setColor(fights->place.hud[i].text, sfBlack);
    sfText_setPosition(fights->place.hud[i].text, (sfVector2f)
        {text_pos[i - 5].x, text_pos[i - 5].y});
}

void enemies_life(struct fight_s *fights, sfColor color)
{
    sfVector2f bar_pos[3] = {{1247, 505}, {1247, 557}, {1247, 608}};
    sfVector2f text_pos[3] = {{1308, 504}, {1308, 556}, {1308, 607}};

    for (int i = 5; i < 8; i++) {
        fights->place.hud[i].sprite = sfSprite_create();
        fights->place.hud[i].texture =
            sfTexture_createFromFile("assets/bars_states/full.png", NULL);
        sfSprite_setTexture(fights->place.hud[i].sprite,
            fights->place.hud[i].texture, sfTrue);
        sfSprite_setColor(fights->place.hud[i].sprite, color);
        sfSprite_setPosition(fights->place.hud[i].sprite,
            (sfVector2f){bar_pos[i - 5].x, bar_pos[i - 5].y});
        set_text(fights, text_pos, i);
    }
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** fightscene
*/

#include "rpg.h"

static void animation_ceo(rpg_t *rpg, struct fight_s *fights)
{
    player_animation(fights);
    sfRenderWindow_drawSprite(rpg->window.window, fights->player.sprite, NULL);
    if (fights->place.fight) {
        for (unsigned int i = 0; i < 3; i++) {
            enemies_animation(fights, i);
            sfRenderWindow_drawSprite(rpg->window.window,
                fights->place.enemies[i].sprite, NULL);
        }
    }
    if (fights->control.fight) {
        boss_animation(fights);
        sfRenderWindow_drawSprite(rpg->window.window,
            fights->control.enemy.sprite, NULL);
    }
}

void fightscene(rpg_t *rpg, struct fight_s *fights)
{
    animation_ceo(rpg, fights);
    if (fights->place.fight) {
        place_scene(rpg, fights);
    }
    if (fights->control.fight) {
        upd8_player_datas(fights);
        control_scene(rpg, fights);
    }
}

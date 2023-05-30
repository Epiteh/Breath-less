/*
** EPITECH PROJECT, 2023
** Epiteh-Engine
** File description:
** loop
*/

#include "rpg.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static void clear_my_game(rpg_t *rpg)
{
    free_menu(rpg);
    destroy_collectibles(rpg);
    destroy_font(rpg);
    destroy_missions(rpg);
    destroy_npc(rpg);
    sfRenderWindow_destroy(rpg->window.window);
    sfSprite_destroy(rpg->background.sprite);
}

static void handle_event_game(rpg_t *rpg)
{
    if (rpg->fights.place.fight &&
            rpg->fights.player_turn) {
                handle_choice(&rpg->fights);
    }
    if (rpg->fights.control.fight &&
            rpg->fights.player_turn) {
                handle_bosschoice(&rpg->fights);
    }
    escape_button_event(rpg);
    close_settings_menu(rpg);
    inventory_event(rpg);
    char_creator_event(rpg);
    save_ceo_event(rpg);
}

static void event_game_loop(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->window.window, &rpg->window.event)) {
        if (rpg->window.event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window.window);
        if (rpg->window.event.type == sfEvtKeyPressed &&
            rpg->window.event.key.code == sfKeyA)
            sfRenderWindow_close(rpg->window.window);
        if (rpg->start.is_start) {
            start_button_event(rpg);
        }
    handle_event_game(rpg);
    }
}

static void manage_loop(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->window.window, sfBlack);
    handle_scene(rpg);
    handle_fight(rpg);
    change_scene(rpg);
    mission_scene(rpg);
    sfRenderWindow_display(rpg->window.window);
}

void main_game_loop(rpg_t *rpg)
{
    srand(time(NULL));
    init_values(rpg);
    sfSprite_setTextureRect(rpg->sprite.sprite, rpg->sprite.rect);
    rpg->fights.player_turn = true;
    rpg->fights.attacked = false;
    init_tp_player(rpg, 516, 936);
    while (sfRenderWindow_isOpen(rpg->window.window)) {
        event_game_loop(rpg);
        manage_loop(rpg);
    }
    clear_my_game(rpg);
}

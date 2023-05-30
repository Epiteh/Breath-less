/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** player
*/

#include "rpg.h"

static void init_player_plattacks(struct fight_s *fights)
{
    fights->player.datas.attacks =
        my_calloc(sizeof(*fights->player.datas.attacks), 3);
    fights->player.datas.attacks[0].name = "Slash";
    fights->player.datas.attacks[0].damage = 15;
    fights->player.datas.attacks[0].speed = 15;
    fights->player.datas.attacks[0].available = true;
    fights->player.datas.attacks[1].name = "Cross Stomp";
    fights->player.datas.attacks[1].damage = 20;
    fights->player.datas.attacks[1].speed = 8;
    fights->player.datas.attacks[1].available = true;
    fights->player.datas.attacks[2].name = NULL;
    fights->player.datas.attacks[2].damage = 0;
    fights->player.datas.attacks[2].speed = 0;
    fights->player.datas.attacks[2].available = false;
}

static void init_player_datas(struct fight_s *fights)
{
    fights->player.datas.max_hp = 200;
    fights->player.datas.hp = 200;
    fights->player.datas.defense = 1.2;
    fights->player.datas.level = 0;
    fights->player.datas.mindfulness = 100;
    fights->player.datas.speed = 100;
    fights->player.datas.damage = 0;
    fights->player.datas.xp = 0;
    init_player_plattacks(fights);
}

void init_player(struct fight_s *fights)
{
    fights->player.sprite = sfSprite_create();
    fights->player.texture = sfTexture_createFromFile("assets/fight.png", NULL);
    sfSprite_setTexture(fights->player.sprite, fights->player.texture, sfTrue);
    sfSprite_setPosition(fights->player.sprite, (sfVector2f){550, 470});
    sfSprite_setScale(fights->player.sprite, (sfVector2f){4, 4});
    fights->player.rect = (sfIntRect){0, 0, 32, 32};
    fights->player.clock = sfClock_create();
    sfSprite_setTextureRect(fights->player.sprite, fights->player.rect);
    init_player_datas(fights);
}

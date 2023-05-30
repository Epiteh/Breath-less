/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** boss
*/

#include "rpg.h"

static void init_boss_attacks(struct fight_s *fights)
{
    fights->control.enemy.datas.attacks = my_calloc(3, sizeof(struct attacks));
    fights->control.enemy.datas.attacks[0].name = my_strdup("Geeked up");
    fights->control.enemy.datas.attacks[0].damage = 25;
    fights->control.enemy.datas.attacks[0].speed = 20;
    fights->control.enemy.datas.attacks[0].available = true;
    fights->control.enemy.datas.attacks[1].name = my_strdup("Plug-in");
    fights->control.enemy.datas.attacks[1].damage = 50;
    fights->control.enemy.datas.attacks[1].speed = 50;
    fights->control.enemy.datas.attacks[1].available = true;
    fights->control.enemy.datas.attacks[2].name = my_strdup("Infinit malloc");
    fights->control.enemy.datas.attacks[2].damage = 100;
    fights->control.enemy.datas.attacks[2].speed = 100;
    fights->control.enemy.datas.attacks[2].available = true;

}

static void init_boss_datas(struct fight_s *fights)
{
    fights->control.enemy.datas.max_hp = 850;
    fights->control.enemy.datas.hp = 850;
    fights->control.enemy.datas.damage = 50;
    fights->control.enemy.datas.defense = 50;
    fights->control.enemy.datas.mindfulness = -900000;
    fights->control.enemy.datas.level = 99;
    fights->control.enemy.datas.speed = 199;
    fights->control.enemy.datas.dead = false;
    init_boss_attacks(fights);
}

static void init_boss(struct fight_s *fights)
{
    fights->control.enemy.clock = sfClock_create();
    fights->control.enemy.sprite = sfSprite_create();
    fights->control.enemy.texture = sfTexture_createFromFile(
        "assets/boss.png", NULL);
    sfSprite_setTexture(fights->control.enemy.sprite,
        fights->control.enemy.texture, sfTrue);
    fights->control.enemy.rect = (sfIntRect){0, 0, 64, 64};
    sfSprite_setTextureRect(fights->control.enemy.sprite,
        fights->control.enemy.rect);
    sfSprite_setScale(fights->control.enemy.sprite, (sfVector2f){4, 4});
    fights->control.enemy.position = (sfVector2f){1160, 105};
    sfSprite_setPosition(fights->control.enemy.sprite,
        fights->control.enemy.position);
    init_boss_datas(fights);
}

void init_control(struct fight_s *fights)
{
    fights->control.fight = false;
    fights->control.clock = sfClock_create();
    fights->control.sprite = sfSprite_create();
    fights->control.texture = sfTexture_createFromFile(
        "assets/fightscene.png", NULL);
    sfSprite_setTexture(fights->control.sprite,
        fights->control.texture, sfTrue);
    sfSprite_setScale(fights->control.sprite, (sfVector2f){1, 0.95});
    init_boss(fights);
}

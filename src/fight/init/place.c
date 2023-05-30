/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** place
*/

#include "rpg.h"

static void init_place_attacks(struct fight_s *fights)
{
    for (unsigned int j = 0; j < (unsigned int)3; j++) {
        fights->place.enemies[j].datas.attacks =
            my_calloc(sizeof(*fights->place.enemies->datas.attacks), 3);
        fights->place.enemies[j].datas.attacks[0].name = "New Order";
        fights->place.enemies[j].datas.attacks[0].damage = 5;
        fights->place.enemies[j].datas.attacks[0].speed = 15;
        fights->place.enemies[j].datas.attacks[0].available = true;
        fights->place.enemies[j].datas.attacks[1].name = "Rotating Laser";
        fights->place.enemies[j].datas.attacks[1].damage = 8;
        fights->place.enemies[j].datas.attacks[1].speed = 8;
        fights->place.enemies[j].datas.attacks[1].available = true;
        fights->place.enemies[j].datas.attacks[2].name = "Hardware Error";
        fights->place.enemies[j].datas.attacks[2].damage = 15;
        fights->place.enemies[j].datas.attacks[2].speed = 5;
        fights->place.enemies[j].datas.attacks[2].available = true;
    }
}

static void init_plenemies_datas(struct fight_s *fights, int i)
{
    fights->place.enemies[i].sprite = sfSprite_create();
    sfSprite_setTexture(fights->place.enemies[i].sprite,
        fights->place.enemies[i].texture, sfTrue);
    sfSprite_setPosition(fights->place.enemies[i].sprite,
        fights->place.enm_pos[i]);
    sfSprite_setScale(fights->place.enemies[i].sprite, (sfVector2f){1.7, 1.7});
    fights->place.enemies[i].rect = (sfIntRect){0, 0, 98, 98};
    sfSprite_setTextureRect(fights->place.enemies[i].sprite,
        fights->place.enemies[i].rect);
    fights->place.enemies[i].datas.hp = 100;
    fights->place.enemies[i].datas.defense = 10;
    fights->place.enemies[i].datas.level = 2;
    fights->place.enemies[i].datas.mindfulness = 0;
    fights->place.enemies[i].datas.speed = 10;
    fights->place.enemies[i].datas.damage = 10;
    fights->place.enemies[i].datas.xp = 0;
    fights->place.enemies[i].datas.dead = false;
    fights->place.enemies[i].clock = sfClock_create();
}

static void init_place_enemies(struct fight_s *fights)
{
    fights->place.enm_pos = my_calloc(sizeof(*fights->place.enm_pos), 3);
    fights->place.enm_pos[0] = (sfVector2f){1110, 80};
    fights->place.enm_pos[1] = (sfVector2f){1210, 230};
    fights->place.enm_pos[2] = (sfVector2f){1315, 80};
    fights->place.enemies[0].texture =
        sfTexture_createFromFile("assets/enemy3.png", NULL);
    fights->place.enemies[1].texture =
        sfTexture_createFromFile("assets/enemy2.png", NULL);
    fights->place.enemies[2].texture =
        sfTexture_createFromFile("assets/enemy.png", NULL);
    for (unsigned int i = 0; i < 3; i++) {
        init_plenemies_datas(fights, i);
        init_place_attacks(fights);
    }
}

void init_place(struct fight_s *fights)
{
    fights->place.fight = false;
    fights->place.clock = sfClock_create();
    fights->place.sprite = sfSprite_create();
    fights->place.texture =
        sfTexture_createFromFile("assets/fightscene2.png", NULL);
    sfSprite_setTexture(fights->place.sprite, fights->place.texture, sfTrue);
    sfSprite_setPosition(fights->place.sprite, (sfVector2f){0, 0});
    sfSprite_setScale(fights->place.sprite, (sfVector2f){1, 1});
    fights->place.enemies_left = 3;
    fights->place.enemies = my_calloc(sizeof(*fights->place.enemies), 3);
    init_place_enemies(fights);
}

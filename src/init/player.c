/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#include "rpg.h"

void init_sprite(rpg_t *rpg)
{
    rpg->sprite.position = (sfVector2f){390, 200};
    rpg->sprite.screen_pos = (sfVector2f){0, 0};
    rpg->sprite.sprite = sfSprite_create();
    rpg->sprite.clock = sfClock_create();
    rpg->sprite.sprite_path = "./assets/characters/mc/lucy_down.png";
    rpg->sprite.texture = sfTexture_createFromFile(
        rpg->sprite.sprite_path, NULL);
    sfSprite_setTexture(rpg->sprite.sprite, rpg->sprite.texture, sfFalse);
    rpg->sprite.rect.width = 32;
    rpg->sprite.rect.height = 32;
    rpg->sprite.rect.left = 0;
    rpg->sprite.rect.top = 0;
    rpg->sprite.sprite_size = (sfVector2f){2, 2};
    rpg->sprite.hitbox_size = (sfVector2f){30, 55};
    sfSprite_setTextureRect(rpg->sprite.sprite, rpg->sprite.rect);
    sfSprite_setScale(rpg->sprite.sprite, rpg->sprite.sprite_size);
}

void init_view(rpg_t *rpg)
{
    sfFloatRect size = {0, 0, 1920, 1080};

    rpg->view.view = sfView_createFromRect(size);
    sfImage *mapIm = sfImage_createFromFile("assets/map/map.png");
    rpg->view.Smap = sfSprite_create();
    rpg->view.rect.top = (rpg->sprite.position.x - 1920) / 2;
    rpg->view.rect.left = (rpg->sprite.position.y - 1080) / 2;
    rpg->view.rect.width = 1920;
    rpg->view.rect.height = 1080;
    rpg->view.Tmap = sfTexture_createFromImage(mapIm, &rpg->view.rect);
    sfSprite_setTexture(rpg->view.Smap, rpg->view.Tmap, sfFalse);
    sfImage_destroy(mapIm);
}

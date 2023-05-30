/*
** EPITECH PROJECT, 2023
** Collectible
** File description:
** knife.c
*/

#include "rpg.h"

static int load_knife(rpg_t *rpg)
{
    rpg->collectible.knife.texture =
        sfTexture_createFromFile("assets/collectibles/knife_1.png", NULL);
    if (!rpg->collectible.knife.texture) {
        return (84);
    }
    rpg->collectible.knife.sprite = sfSprite_create();
    sfSprite_setTexture(rpg->collectible.knife.sprite,
        rpg->collectible.knife.texture, sfTrue);
    rpg->collectible.knife.pos = (sfVector2f) {425 + 95, 175 + 20};
    sfSprite_setPosition(rpg->collectible.knife.sprite,
        rpg->collectible.knife.pos);
    sfSprite_setOrigin(rpg->collectible.knife.sprite, (sfVector2f) {16, 16});
    sfSprite_setRotation(rpg->collectible.knife.sprite, -72);
    sfSprite_setScale(rpg->collectible.knife.sprite,
        (sfVector2f) {1.2, 1.2});
    return (0);
}

static void rect_creation(rpg_t *rpg)
{
    rpg->collectible.knife.rect = sfRectangleShape_create();
    rpg->collectible.knife.rect_pos = (sfVector2f) {410 + 60, 160 - 20};
    sfRectangleShape_setPosition(rpg->collectible.knife.rect,
        rpg->collectible.knife.rect_pos);
    sfRectangleShape_setSize(rpg->collectible.knife.rect,
        (sfVector2f){115, 115});
    sfRectangleShape_setFillColor(rpg->collectible.knife.rect,
        sfTransparent);
    sfRectangleShape_setOutlineColor(rpg->collectible.knife.rect, sfRed);
    rpg->collectible.knife.e_interaction = sfSprite_create();
    sfSprite_setTexture(rpg->collectible.knife.e_interaction,
        rpg->collectible.texture_first_e_inter, sfTrue);
    sfSprite_setPosition(rpg->collectible.knife.e_interaction,
        (sfVector2f) {430 + 70, 175 - 50});
    sfSprite_setScale(rpg->collectible.knife.e_interaction,
        (sfVector2f) {0.9, 0.9});
    rpg->collectible.last_second = 0;
}

int init_knife(rpg_t *rpg)
{
    if (load_knife(rpg) == 84) {
        return (84);
    }
    rect_creation(rpg);
    rpg->collectible.knife.get = false;
    rpg->collectible.knife.collision = false;
    return (0);
}

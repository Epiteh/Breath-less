/*
** EPITECH PROJECT, 2023
** RPG_MISSION
** File description:
** draw_text_npc.c
*/

#include "rpg.h"
#include <stdlib.h>

bool draw_text_npc(rpg_t *rpg, char *message_content, sfText *message,
    unsigned int *letter_counter)
{
    char *texte = message_content;
    unsigned int longueur = my_strlen(texte);
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(
        rpg->collectible.npc_text_clock));
    char *sous_chaine = my_calloc(*letter_counter + 2, sizeof(char));

    if (sec >= 0.09 && *letter_counter < longueur) {
        my_strncpy(sous_chaine, texte, *letter_counter + 1);
        sous_chaine[*letter_counter + 1] = '\0';
        sfText_setString(message, sous_chaine);
        *letter_counter += 1;
        sfClock_restart(rpg->collectible.npc_text_clock);
    }
    free(sous_chaine);
    sfRenderTexture_drawText(rpg->background.map_render_texture, message, NULL);
    if (longueur == *letter_counter)
        return (true);
    return (false);
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-titouan.donin
** File description:
** draw.c
*/

#include "rpg.h"
#include <stdlib.h>
#include <stdio.h>

bool draw_mission_text(rpg_t *rpg, char *message_content, sfText *message,
    unsigned int *letter_counter)
{
    char *texte = message_content;
    unsigned int longueur = my_strlen(texte);
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(
        rpg->mission_text.clock));
    char *sous_chaine = my_calloc(*letter_counter + 3, sizeof(char));

    if (sec >= 0.09 && *letter_counter < longueur) {
        my_strncpy(sous_chaine, texte, *letter_counter + 1);
        sous_chaine[*letter_counter + 1] = '\0';
        sfText_setString(message, sous_chaine);
        *letter_counter += 1;
        sfClock_restart(rpg->mission_text.clock);
    }
    free(sous_chaine);
    sfRenderWindow_drawText(rpg->window.window, message, NULL);
    if (*letter_counter == longueur)
        return (false);
    return (true);
}

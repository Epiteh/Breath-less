/*
** EPITECH PROJECT, 2023
** B-PSU-200-NAN-2-1-minishell1-sasha.dupeyroux
** File description:
** my_strcat2
*/

#include "../include/my.h"

char *my_strcat2(char *str1, char *str2)
{
    int size = my_strlen(str1) + my_strlen(str2);
    char *buffer = my_calloc(sizeof(char), size + 1);
    int tmp = 0;

    for (int i = 0; str1[i] != '\0' && str1[i] != '\n'; i++, tmp++) {
        buffer[tmp] = str1[i];
    }
    for (int i = 0; str2[i] != '\0' && str2[i] != '\n'; i++, tmp++) {
        buffer[tmp] = str2[i];
    }
    buffer[tmp] = '\0';

    return (buffer);
}

/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** Coies n characters from a string into another
*/
#include "../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int str_length = my_strlen(src);

    for (; i < n; i++) {
        dest[i] = src[i];
    }
    if (n > str_length) {
        dest[i] = '\0';
    }
    return dest;
}

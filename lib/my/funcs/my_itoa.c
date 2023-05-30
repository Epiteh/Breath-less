/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** my_itoa
*/

#include "../include/my.h"

void reverse(char *str)
{
    unsigned int i;
    unsigned int j;
    char tmp;

    for (i = 0, j = my_strlen(str) - 1; i < j; i++, j--) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

void my_itoa(int nb, char *str)
{
    unsigned int i;
    unsigned int sign;

    i = 0;
    sign = 0;

    if ((sign = nb) < 0)
        nb = -nb;
    do {
        str[i++] = nb % 10 + '0';
    } while ((nb /= 10) > 0);
    if (sign < 0)
        str[i++] = '-';
    str[i] = '\0';
    reverse(str);
}

/*
** EPITECH PROJECT, 2023
** B-PSU-100-NAN-1-1-navy-sasha.dupeyroux
** File description:
** my_strcmp
*/
#include "../include/my.h"

int my_strcmp(const char *str1, const char *str2)
{
    unsigned int first_len = (unsigned int) my_strlen(str1);
    unsigned int second_len = (unsigned int) my_strlen(str2);

    if (first_len != second_len) {
        return (1);
    }
    for (unsigned int i = 0; i < first_len; i ++) {
        if (str1[i] != str2[i]) {
            return (1);
        }
    }
    return (0);
}

/*
** EPITECH PROJECT, 2023
** B-PSU-100-NAN-1-1-navy-sasha.dupeyroux
** File description:
** my_calloc
*/

#include "../include/my.h"
#include <stdlib.h>

void *my_calloc(int element, int size)
{
    void *ptr = malloc(element * size);

    if (!ptr)
        return (NULL);
    my_memset(ptr, 0, element * size);
    return (ptr);
}

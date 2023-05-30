/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_put_nbr
*/

#include "unistd.h"

int my_put_nbr(int nb)
{
    int result;

    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * (-1);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else {
        result = nb + '0';
        write(1, &result, 1);
    }
}

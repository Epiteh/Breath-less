/*
** EPITECH PROJECT, 2023
** B-PSU-100-NAN-1-1-navy-sasha.dupeyroux
** File description:
** isdigits
*/

int isdigits(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

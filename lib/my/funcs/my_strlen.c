/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    for (int i = 0; ; i++) {
        if (str[i] == '\0')
            return i;
    }
}

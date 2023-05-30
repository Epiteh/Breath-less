/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_strcpy
*/

void my_strcpy(char *src, char* dest)
{
    int i = 0;
    while ((dest[i] = src[i]) != '\0')
        i++;
}

/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    for (i; str[i] == '-' || str[i] == '+' ||
        str[i] < '0' || str[i] > '9'; i++) {
            if (str[i] == '-') {
                sign = -sign;
            }
        }
    for (i; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {
        result = result * 10 + str[i] - '0';
    }
    if (sign == -1) {
        result = -result;
    }
    return (result);
}

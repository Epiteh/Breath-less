/*
** EPITECH PROJECT, 2023
** read_html_file
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

void *my_calloc(int element, int size);
void *my_memset(void *ptr, int count, int size);
int my_putstr(char const *str);
int my_strlen(char const *str);
int isdigits(char c);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_strcmp(const char *str1, const char *str2);
void my_strcpy(char *src, char* dest);
void my_itoa(int n, char *s);
char *my_strdup(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat2(char *str1, char *str2);

#endif /* !MY_H_ */

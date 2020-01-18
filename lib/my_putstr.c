/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** putstr
*/

#include "basic.h"

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}

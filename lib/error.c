/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error
*/

#include "basic.h"

/*
\fn void put_error(char *str)
\brief put string on standard error output
\param str : the string to print.
\return nothing.
*/

void my_putchar_2(char c)
{
    write(2, &c, 1);
}

void put_error(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_2(str[i]);
        i++;
    }
}


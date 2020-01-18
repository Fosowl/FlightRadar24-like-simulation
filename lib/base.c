/*
** EPITECH PROJECT, 2019
** base.c
** File description:
** base
*/

#include "basic.h"

/*
\fn int nb_to_binary(char *str)
\brief convert number to binary
\param str : the number to convert
\return a string that represent the number in binary
*/

int nb_to_binary(char *str)
{
    int i = 0;
    int nb = 0;

    while (nb > 0) {
        str[i] = (nb % 2) + 48;
        nb /= 2;
        i += 1;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}

/*
\fn int binary_to_nb(char *str)
\brief convert binary to number
\param str : the binary number to convert
\return decimal number
*/

int binary_to_nb(char *str)
{
    int nb = 0;
    int base1 = 1;
    int len = 0;

    while (str[len] != '\0') {
        len += 1;
    }
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == '1')
            nb += base1;
        base1 = base1 * 2;
    }
    return (nb);
}
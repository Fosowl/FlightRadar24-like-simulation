/*
** EPITECH PROJECT, 2019
** conversion.c
** File description:
** convert
*/

#include "basic.h"

/*
\fn long long my_atoi(char *str)
\brief convert string to number
\param str : the string that represent the number
\return a int that represent the number
*/

long long my_atoi(char *str)
{
    int val = 0;
    int i = 0;

    if (my_strlen(str) > 18)
        return (0);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return (-84);
    }
    for (; *str; str++)
    {
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        }
        else
            return (val);
    }
    return (val);
}

/*
\fn char *my_itoa(int nb)
\brief convert number to string
\param nb : a int that contain the number you want to convert
\return a string that represent the number
*/

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char) * 100);
    int i = 0;

    while (nb > 9) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i++;
    }
    str[i] = nb % 10 + 48;
    str[i + 1] = '\0';
    str = my_revstr(str);
    return (str);
}
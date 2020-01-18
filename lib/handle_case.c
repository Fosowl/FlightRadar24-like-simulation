/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** handle_case
*/

#include "basic.h"

// sub-function of my_printf

int handle_case(char *str)
{
    int t = 0;
    int d = 0;

    for (int i = 0; str[i] != '\0' ; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            t = octal_to_decimal(str[i]);
            for (d = 1; t > 10; t /= 10) {
                d++;
            }
            for (int e = 3; e > d; e--)
                my_putchar('0');
            put_octal(str[i]);
        } else
            my_putchar(str[i]);
    }
    return (0);
}
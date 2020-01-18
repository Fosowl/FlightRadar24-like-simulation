/*
** EPITECH PROJECT, 2019
** get.c
** File description:
** usefull3 function
*/

#include "basic.h"

/*
\fn int char_in(char c, char *str)
\brief check if a character i inside a string.
\param c : the character to check.
\param str : the string witch you check the character in.
\return -1 if not found else return the index.
*/

int char_in(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (i);
    }
    return (-1);
}

/*
\fn int compare(char *str, char *try)
\brief compare 2 string
\param str : the first string.
\param try : the string to compare with.
\return 1 if the string are identical else return 0.
*/

int compare(char *str, char *try)
{
    int i = 0;
    int o = 0;

    while (str[i] != '\0') {
        if (str[i] == try[i])
            o += 1;
        i += 1;
    }
    if (i == o)
        return (1);
    else
        return (0);
}

/*
\fn int my_strlen(char *str)
\brief measure string lenght
\param str : the string to measure the lenght.
\return the len of the string in a int.
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

/*
\fn int search(char *this, char *in)
\brief search string inside another
\param this : the string that you are looking for.
\return the index if found else return -1
*/

int search(char *this, char *in)
{
    int i = 0;
    int  o = 0;
    int size = my_strlen(this);

    while (in[i] != '\0') {
        if (this[o] == in[i])
            o += 1;
        else
            o = 0;
        if (o == size)
            return (i - my_strlen(this));
        i += 1;
    }
    return (-1);
}

/*
\fn int read_input(char *str)
\brief read user input
\param str : the string that store user input.
\return 0
*/

int read_input(char *str)
{
    char *temp;
    int size = 0;
    int ret = 0;

    temp = malloc(sizeof(char) * 10);
    temp[1] = '\0';
    while (1) {
        ret = read(1, temp, 1);
        if (ret == 1)
            return (-1);
        if (temp[0] == '\n')
            break;
        str[size] = temp[0];
        size += 1;
    }
    free(temp);
    str[size] = '\0';
    return (0);
}
/*
** EPITECH PROJECT, 2019
** parsing.c
** File description:
** usefull3 function
*/

#include "basic.h"

/*
\fn int divide_array(char *str, char **result, char separation)
\brief function to divide a string into a 2d array.
\param str : the simple string.
\param result : the 2d string that will contain str.
\separation : the charater to divide the array with.
\return 0.
*/

int divide_array(char *str, char **result, char separation)
{
    int i = 0;
    int o = 0;
    int i3 = 0;

    while (str[i] != '\0') {
        if (str[i] == separation) {
            result[o][i3] = '\0';
            o += 1;
            i3 = -1;
        }
        else {
            result[o][i3] = str[i];
        }
        i += 1;
        i3 += 1;
    }
    return (o);
}

/*
\fn int divide_array(char *str, char **result, char separation)
\brief function to divide a string into a 2d array.
\param str : the simple string.
\param result : the 2d string that will contain str.
\separation : the charater to divide the array with.
\return 0.
*/

void remove_char(char *str, char remove, int rest)
{
    char *cpy;
    int i = 0;
    int k = 0;
    int d = 0;

    cpy = malloc(my_strlen(str) * sizeof(char) + 1);
    cpy = fill(str);
    while (cpy[i] != '\0') {
        if (cpy[i] == remove && cpy[i + 1] != remove)
            d = 0;
        if (cpy[i] == remove)
            d++;
        if (cpy[i] != remove || d <= rest) {
            str[k] = cpy[i];
            k++;
        }
        i++;
    }
    free (cpy);
    str[k] = '\0';
}

/*
\fn int fusion(char *str, char *sticked, int place)
\brief fusion 2 string.
\param str : the first string.
\param sticked : the string that will be sticked to the first one.
\place : the index of sticked in str.
\return 0.
*/

int fusion(char *str, char *sticked, int place)
{
    char *endCopy;
    int i = place;
    int k = 0;

    endCopy = malloc(sizeof(char) * (sizeof(str) - place + 1));
    if (my_strlen(str) < place) {
        while (str[i] != '\0') {
            endCopy[k] = str[i];
            i++;
            k++;
        }
    }
    else
        endCopy[0] = '\0';
    i = place;
    fusion_2(endCopy, str, sticked, i);
    free (endCopy);
    return (0);
}

// sub-function of fusion

void fusion_2(char *endCopy, char *str, char *sticked, int i)
{
    int k = 0;

    while (sticked[k] != '\0') {
        str[i] = sticked[k];
        i++;
        k++;
    }
    k = 0;
    while (endCopy[k] != '\0') {
        str[i] = endCopy[k];
        i++;
        k++;
    }
    str[i] = '\0';
}

/*
\fn char *my_revstr(char *str)
\brief reverse a string.
\param str : the string to reverse.
\return (char *) the reversed string.
*/

char *my_revstr(char *str)
{
    int r = 0;
    int l = 0;
    int lenght = 0;
    char t;

    l = my_strlen(str) - 1;
    lenght = l;
    for (int i = 0; i < lenght / 2 + lenght % 2; i++) {
        t = str[r];
        str[r] = str[l];
        str[l] = t;
        if (l <= r)
            break;
        r++;
        l--;
    }
    return (str);
}
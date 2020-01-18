/*
** EPITECH PROJECT, 2019
** letter.c
** File description:
** letter
*/

#include "basic.h"

/*
\fn int compare_letter(char l1, char l2)
\brief compare 2 letter and ignore case
\param l1 : (char) first character.
\param l2 : (char) seconf character.
\return 1 if char are same letter and 0 if not the case
*/

int compare_letter(char l1, char l2)
{
    if (l1 == l2)
        return (1);
    if (l1 >= 97 && l1 <= 122) {
        if (l1 - 32 == l2)
            return (1);
    }
    else {
        if (l1 + 32 == l2)
            return (1);
    }
    return (0);
}

/*
\fn int is_number(char *c)
\brief check if character is a number
\param c : (char) character to check.
\return 1 if character is a number
*/

int is_number(char *c)
{
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] >= 48 && c[i] <= 57)
            continue;
        return (0);
    }
    return (1);
}

/*
\fn int is_number(char *c)
\brief check if character is a number
\param c : (char) character to check.
\return 1 if character is a number
*/

void empty_string(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = '\0';
}

/*
\fn char *insert(char *str, char pushed)
\brief insert character at beginning of string.
\param str : (char *) string to insert the character in.
\return (char *) string with character inserted.
*/

char *insert(char *str, char pushed)
{
    char *increased = NULL;
    int i;

    increased = malloc(sizeof(char) * my_strlen(str) + 10);
    if (increased == NULL)
        return (NULL);
    increased[0] = pushed;
    for (i = 0; str[i] != '\0'; i++)
        increased[i + 1] = str[i];
    increased[i + 1] = '\0';
    return (increased);
}

char *capitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = str[i] - 32;
    return (str);
}
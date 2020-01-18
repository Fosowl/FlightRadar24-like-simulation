/*
** EPITECH PROJECT, 2019
** initialize.c
** File description:
** usefull function
*/

#include "basic.h"

/*
\fn char *clean_alloc(int size)
\brief allocate string and fill it with '\0'
\param size : the memory size to malloc.
\return str
*/

char *clean_alloc(int size)
{
    char *str = NULL;

    str = malloc(size);
    if (str == NULL) {
        my_putstr("allocation error !");
        return (NULL);
    }
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}

/*
\fn char *fill(char *with)
\brief fill string with another
\param with : the string to fill with.
\return this : the string filled with one pass in argument
*/

char *fill(char *with)
{
    int i = 0;
    char *this = NULL;

    this = clean_alloc(sizeof(char) * my_strlen(with) + 2);
    if (this == NULL)
        return (NULL);
    for (i = 0; with[i] != '\0'; i++) {
        this[i] = with[i];
    }
    this[i] = '\0';
    return (this);
}

/*
\fn void fill_double(char **dest, char **temp, int nb)
\brief copy 2d array into another
\param dest : the 2d array you fill.
\param temp : the 2d array that fill dest
\return nothing
*/

void fill_double(char **dest, char **temp, int nb)
{
    int	i = 0;
    int o = 0;

    while (o < nb) {
        while (temp[o][i] != '\0')
        {
            dest[o][i] = temp[o][i];
            i = i + 1;
        }
        dest[o][i] = '\0';
        i = 0;
        o += 1;
    }
}

/*
\fn char *load_files(char *path)
\brief load file into buffer
\param dest : the 2d array you fill.
\param temp : the 2d array that fill dest
\return nothing
*/

char *load_file(char *path)
{
    char *readed = clean_alloc(100);
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;


    stream = fopen(path, "r");
    if (stream == NULL) {
        my_putstr("error opening file !\n");
        return (NULL);
    }
    while ((nread = getline(&line, &len, stream)) != -1) {
        readed = append(readed, line);
    }
    return (readed);
}

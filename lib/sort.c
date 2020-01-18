/*
** EPITECH PROJECT, 2019
** sort
** File description:
** sort a int array
*/

#include "basic.h"

void my_sort_int_array(int *array, int size)
{
    int temp = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > array[i + 1]) {
            temp = array[i];
            array[i] =  array[i + 1];
            array[i + 1] = temp;
        }
    }
    for (int b = 0; b < size; b++) {
        if (!(array[b] <= array[b + 1]))
            my_sort_int_array(array, size);
    }
}
/*
** EPITECH PROJECT, 2018
** basic.h
** File description:
** lib
*/

#ifndef S
#define S

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>

int my_strlen(char *str);
void empty_string(char *str);
char *fill(char *with);
void fill_double(char **dest, char **temp, int nb);
char *clean_alloc(int size);
void my_putchar(char c);
void put_error(char *str);
int my_put_nbr(int nb);
void my_putstr(char *str);
char *my_revstr(char *str);
int nb_to_binary(char *str);
int binary_to_nb(char *str);
int octal_to_decimal(int decimalNumber);
long long my_atoi(char *str);
int read_input(char *str);
int read_file(char *save, char *path);
int fusion(char *str, char *sticked, int place);
void fusion_2(char *endCopy, char *str, char *sticked, int i);
int divide_array(char *str, char **result, char separation);
int compare(char *str, char *try);
void remove_char(char *str, char remove, int rest);
int search(char *this, char *in);
char *my_itoa(int nb);
char *replace(char *str, char *this, char *with);
void save_tail(int r, char *str, char *tail, char *this);
void add_tail_and_word(char *replaced, char *tail, char *this);
void my_sort_int_array(int *array, int size);
int my_print_float(float percent);
int my_print_float_2(char *reversed, int digit);
char *insert(char *str, char pushed);
int is_number(char *c);
int char_in(char c, char *str);

void put_ptr(void *adress);
int my_printf(char *str, ...);
void cast_and_call(int r, va_list list);
void load_function_adress(void (*call[]) (void *));
int handle_case(char *str);
char *capitalize(char *str);
char *calculate_hexa(int nb);
void put_hexa(int nb);
void put_capital_hexa(int nb);
void put_binary(int nb);
void put_octal(int nb);
char *format_from_human_base(char *calculated, char *base);
char revaluate(int num, char *base);
char *load_file(char *path);
char *append(char *origin, char *added);

#endif

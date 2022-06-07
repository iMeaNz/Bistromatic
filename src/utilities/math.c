/*
** EPITECH PROJECT, 2021
** MATH
** File description:
** Math stuff
*/

#include "my.h"
#include <stdlib.h>

char *str_initialize_alloc(char *input, int size);
char *my_mul(char *number1, char *number2);

char *my_power_str(char *number, int power)
{
    int len = my_strlen(number);
    char *tmp = malloc(sizeof(char) * len + 1);
    str_initialize_alloc(tmp, len + 1);
    if (power == 0) {
        tmp[0] = '1';
        tmp[1] = '\0';
        return tmp;
    }
    my_strcpy(tmp, number);

    for (int i = 0; i < power - 1; i++) {
        char *previous_tmp = tmp;
        tmp = my_mul(tmp, number);
        free(previous_tmp);
    }
    return tmp;
}

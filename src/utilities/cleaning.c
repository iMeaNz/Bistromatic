/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Cleaning strings before
*/

#include <stdlib.h>
#include "bistromatic.h"

int my_strlen(char *input);

char *remove_sign(char *input)
{
    char *output = NULL;
    int i = 0;

    if (input[0] != '-')
        return (input);
    output = malloc(sizeof(char) * (my_strlen(input) + 1));
    for (i = 1; i < my_strlen(input); i++)
        output[i - 1] = input[i];
    output[i - 1] = '\0';
    return (output);
}

char *clean_zero_before(char *input)
{
    int size = my_strlen(input);
    char *output = malloc(sizeof(char) * (size + 1));
    int temp_index = input[0] == '-' || input[0] == '+';
    int passed = 0;

    if (temp_index)
        output[0] = input[0];
    for (int i = temp_index ; i < size ; i++) {
        if (input[i] != '0' || passed) {
            passed = 1;
            output[temp_index++] = input[i];
        }
    }
    if (passed == 0) {
        output[0] = '0';
        output[1] = '\0';
    } else
        output[temp_index] = '\0';
    free(input);
    return (output);
}
/*
** EPITECH PROJECT, 2021
** B-CPE-101-STG-1-1-evalexpr-noah.gosciniak
** File description:
** utils.c
*/

#include "my.h"
#include "my_operators.h"
#include <unistd.h>
#include "bistromatic.h"

operator_t *get_op(operator_t *array, char *str)
{
    int i = 0;

    for (; my_strstr(array[i].symbols, str) == NULL &&
    array[i].weight != 0; i++);
    return (&array[i]);
}

operator_t *get_real_op(operator_t *array, char *str)
{
    int i = 0;

    for (; my_strstr(array[i].real_symbols, str) == NULL &&
    array[i].weight != 0; i++);
    return (&array[i]);
}

static void find_nbr(char const *str, int *start_end, char *base, char *op)
{
    int i = 0;
    char temp[2] = "a";

    start_end[0] = i;
    if (str[i] == op[OP_SUB_IDX] || str[i] == op[OP_PLUS_IDX])
        i = 1;
    temp[0] = str[i];
    while (str[i] != '\0' && my_strstr(base, temp) != 0) {
        i++;
        temp[0] = str[i];
    }
    start_end[1] = i;
}

char *my_slicenbr_base(char const *str, char *base, char *operators)
{
    int start_end[2] = {0, 0};
    char *return_str = NULL;
    int len = 0;

    find_nbr(str, start_end, base, operators);
    len = start_end[1] - start_end[0];
    return_str = malloc(sizeof(char) * (len + 1));
    if (len == 0) {
        return_str[0] = '\0';
        return (return_str);
    }
    for (int i = start_end[0] ; i < start_end[1] ; i++)
        return_str[i] = str[i];
    return_str[len] = '\0';
    return (return_str);
}

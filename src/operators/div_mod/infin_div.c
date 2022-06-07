/*
** EPITECH PROJECT, 2021
** Infin_div & Infin_mod
** File description:
** infin_div
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_operators.h"
#include "mylist.h"
#include "stack.h"
#include "bistromatic.h"
#include "my.h"

char *my_add(char *a, char *b);
int my_lower(char *a, char *b);
int my_lower_equals(char *a, char *b);
int my_greater_equals(char *a, char *b);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_equal(char *a, char *b);
char *put_neg_sign(char *result, int sign);
int my_greater(char *a, char *b);

char *infin_div_two(char *dividend, stack_t *keys, stack_t *values, int mod)
{
    char *previous_sum = NULL;
    char *keys_sum = my_strdup("0");
    char *values_sum = my_strdup("0");

    while (stack_peek(values)[0] != '\0' && stack_peek(keys)[0] != '\0') {
        char *tmp_sum = my_add(values_sum, stack_peek(values));
        if (my_lower_equals(tmp_sum, dividend)) {
            previous_sum = keys_sum;
            keys_sum = my_add(keys_sum, stack_pop(keys));
            free(previous_sum);
            previous_sum = values_sum;
            values_sum = my_add(values_sum, stack_pop(values));
            free(previous_sum);
        } else {
            free(stack_pop(values));
            free(stack_pop(keys));
        }
        free(tmp_sum);
    }
    return (mod ? my_sub(dividend, values_sum) : keys_sum);
}

void create_table(char *divide, char *divisor, stack_t *keys, stack_t *values)
{

    char *temp_value = my_strdup("1");
    char *temp_key = my_strdup("1");

    while (1) {
        temp_value = my_mul(temp_key, divisor);
        if (my_greater(temp_value, divide))
            break;
        stack_push(keys, temp_key);
        stack_push(values, temp_value);
        temp_key = my_mul(temp_key, "2");
    }
    free(temp_value);
    free(temp_key);
}

char *infin_div(char *dividend, char *divisor, int modulo, int sign)
{
    stack_t *keys = stack_create();
    stack_t *values = stack_create();
    char *result = NULL;

    if (divisor[0] == '0') {
        my_putstr(SYNTAX_ERROR_MSG);
        exit (84);
    } else if (my_equal(dividend, divisor)) {
        stack_free(keys);
        stack_free(values);
        return (modulo ? my_strdup("0") : put_neg_sign(my_strdup("1"), sign));
    }
    create_table(dividend, divisor, keys, values);
    result = infin_div_two(dividend, keys, values, modulo);
    stack_free(keys);
    stack_free(values);
    free(dividend);
    free(divisor);
    return (put_neg_sign(result, sign));
}

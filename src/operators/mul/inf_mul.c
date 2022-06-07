/*
** EPITECH PROJECT, 2021
** INF_MUL
** File description:
** Infinite multiplication
*/

#include "my.h"
#include "my_operators.h"

char *str_initialize_alloc(char *input, int size);

void fill_zeros(char *output, int pos, int *index)
{
    for (int i = 0; i < pos; ++i)
        output[(*index)++] = '0';
}

int compute_and_push(int tot, char *tmp, int *index, int carry)
{
    int to_push = tot % 10;
    tmp[(*index)++] = to_push + '0';
    carry = tot / 10;
    return (carry);
}

char *fill_tmp(int i, char *number1, char *number2)
{
    int index = 0;
    int len2 = my_strlen(number2);
    int len_tot = my_strlen(number1) + len2;
    char *tmp = malloc(sizeof(char) * (len_tot + 2));
    str_initialize_alloc(tmp, len_tot + 2);
    int carry = 0;
    for (int j = 0; j < len2; ++j) {
        int tot = (number1[i] - '0') * (number2[j] - '0') + carry;
        carry = compute_and_push(tot, tmp, &index, carry);
    }
    if (carry != 0)
        tmp[index++] = carry + '0';
    my_revstr(tmp);
    tmp[my_strlen(tmp)] = '\0';
    fill_zeros(tmp, i, &index);
    return tmp;
}

char *put_neg_sign(char *result, int sign)
{
    int len = my_strlen(result);
    if (sign == 1)
        return result;
    char *new_result = malloc(sizeof(char) * len + 2);
    str_initialize_alloc(new_result, len + 2);
    new_result[0] = '-';
    for (int i = 1; i < my_strlen(result) + 1; ++i) {
        new_result[i] = result[i - 1];
    }
    free(result);
    return new_result;
}

char *inf_mul(char *number1, char *number2, int sign)
{
    int len1 = my_strlen(number1);
    int len2 = my_strlen(number2);
    int len_tot = len1 + len2;
    char *result = malloc(sizeof(char) * (len_tot + 2));
    char *tmp_res = str_initialize_alloc(result, len_tot + 2);

    my_revstr(number1);
    my_revstr(number2);
    for (int i = 0; i < len1; ++i) {
        char *tmp = fill_tmp(i, number1, number2);
        result = my_add(tmp, tmp_res);
        free(tmp_res);
        tmp_res = result;
        free(tmp);
    }
    result = put_neg_sign(result, sign);
    free(number1);
    free(number2);
    return (result);
}

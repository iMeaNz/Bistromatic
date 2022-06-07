/*
** EPITECH PROJECT, 2021
** inf_add_sub.c
** File description:
** inf_add_sub
*/

#include "my.h"

int cmp_gt(char const *s1, char const *s2);
int my_greater(char *a, char *b);

char *inf_add(char *a, char *b, int len[], char *result)
{
    int max = len[0] > len[1] ? len[0] : len[1];
    int carry = 0;
    int temp = 0;
    char ca = '0';
    char cb = '0' ;

    my_revstr(a);
    my_revstr(b);
    for (int i = 0 ; i < max + 1 ; i++) {
        ca = i < len[0] ? a[i] : '0';
        cb = i < len[1] ? b[i] : '0';
        temp = ca + cb - '0' * 2 + carry;
        carry = temp / 10;
        result[i] = temp % 10 + '0';
    }
    result[max] = result[max] == '0' ? '\0' : result[max];
    if (result[max] != '\0')
        result[max + 1] = '\0';
    return (my_revstr(result));
}

char *compute_sub(char *a, char *b, int len[], char *result)
{
    int max = len[0] > len[1] ? len[0] : len[1];
    int carry = 0;
    int temp = 0;
    char ca = '0';
    char cb = '0';
    int calc = 0;

    for (int i = 0 ; i < max + 1 ; i++) {
        ca = i < len[0] ? a[i] : '0';
        cb = i < len[1] ? b[i] : '0';
        temp = ca - cb - carry;
        carry = temp < 0;
        if (temp < 0)
            temp += 10;
        calc = temp % 10;
        result[i] = i >= len[0] && calc == 0 ? '\0' : calc + '0';
    }
    result[max] = '\0';
    return (my_revstr(result));
}

char *inf_sub(char *a, char *b, int negs[], char *result)
{
    int pos_max = my_greater(a, b) ? 0 : 1;
    char *max = pos_max == 1 ? b : a;
    char *min = pos_max == 1 ? a : b;
    int len[2];

    my_revstr(a);
    my_revstr(b);
    len[0] = my_strlen(max);
    len[1] = my_strlen(min);
    if (negs[pos_max]) {
        result[0] = '-';
        compute_sub(max, min, len, &result[1]);
    } else
        compute_sub(max, min, len, result);
    return (result);
}

char *inf_add_sub(char *a, char *b, int neg_a, int neg_b)
{
    int len[2] = {my_strlen(a), my_strlen(b)};
    int max = len[0] > len[1] ? len[0] : len[1];
    char *result = malloc(sizeof(char) * (max + 3));
    int negs[2] = {neg_a, neg_b};

    if (neg_a && neg_b) {
        result[0] = '-';
        inf_add(a, b, len, &result[1]);
    } else if (neg_a != neg_b) {
        inf_sub(a, b, negs, result);
    } else {
        inf_add(a, b, len, result);
    }
    return (result);
}
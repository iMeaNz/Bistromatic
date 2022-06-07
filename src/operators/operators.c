/*
** EPITECH PROJECT, 2021
** evalxpr
** File description:
** operators.c
*/

#include <unistd.h>
#include "my.h"
#include "my_operators.h"

char *inf_add_sub(char *a, char *b, int neg_a, int neg_b);
char *infin_div(char *a, char *b, int modulo, int sign);
char *add_minus(char *input);
char *int_to_str(int nb);
char *inf_mul(char *number1, char *number2, int sign);
char *remove_sign(char *input);

char *my_mul(char *a, char *b)
{
    int neg_a = 0;
    int neg_b = 0;
    char *result = NULL;
    char *s1 = my_strdup(a);
    char *s2 = my_strdup(b);

    neg_a = s1[0] == '-';
    neg_b = s2[0] == '-';
    result = inf_mul(remove_sign(s1), remove_sign(s2), neg_a == neg_b);
    if (neg_a)
        free(s1);
    if (neg_b)
        free(s2);
    return (result);
}

char *my_div(char *a, char *b)
{
    int neg_a = 0;
    int neg_b = 0;
    char *result = NULL;
    char *s1 = my_strdup(a);
    char *s2 = my_strdup(b);

    neg_a = s1[0] == '-';
    neg_b = s2[0] == '-';
    result = infin_div(remove_sign(s1), remove_sign(s2), 0, neg_a == neg_b);
    if (neg_a)
        free(s1);
    if (neg_b)
        free(s2);
    return (result);
}

char *my_sub(char *a, char *b)
{
    int neg_a = 0;
    int neg_b = 0;
    char *result = NULL;
    char *s1 = my_strdup(a);
    char *s2 = my_strdup(b);

    neg_a = s1[0] == '-';
    neg_b = s2[0] == '-';
    result = inf_add_sub(neg_a ? &s1[1] : s1,
    neg_b ? &s2[1] : s2, neg_a, !neg_b);
    free(s1);
    free(s2);
    return (result);
}

char *my_add(char *a, char *b)
{
    int neg_a = 0;
    int neg_b = 0;
    char *result = NULL;
    char *s1 = my_strdup(a);
    char *s2 = my_strdup(b);

    neg_a = s1[0] == '-';
    neg_b = s2[0] == '-';
    result = inf_add_sub(neg_a ? &s1[1] : s1,
    neg_b ? &s2[1] : s2, neg_a, neg_b);
    free(s1);
    free(s2);
    return (result);
}

char *my_mod(char *a, char *b)
{
    int neg_a = 0;
    int neg_b = 0;
    char *result = NULL;
    char *s1 = my_strdup(a);
    char *s2 = my_strdup(b);

    neg_a = s1[0] == '-';
    neg_b = s2[0] == '-';
    result = infin_div(remove_sign(s1), remove_sign(s2), 1, !neg_a);
    if (neg_a)
        free(s1);
    if (neg_b)
        free(s2);
    return (result);
}

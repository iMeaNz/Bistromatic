/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** Check conditions
*/

int cmp_gt(char const *s1, char const *s2);

int my_equal(char *a, char *b)
{
    char *str1 = a;
    char *str2 = b;
    int cmp = cmp_gt(str1, str2);

    if (cmp == 0)
        return (1);
    return (0);
}

int my_greater(char *a, char *b)
{
    char *str1 = a;
    char *str2 = b;
    int cmp = cmp_gt(str1, str2);

    if (cmp >= 1)
        return (1);
    return (0);
}

int my_lower_equals(char *a, char *b)
{
    char *str1 = a;
    char *str2 = b;
    int cmp = cmp_gt(str1, str2);

    if (cmp <= 0)
        return (1);
    return (0);
}

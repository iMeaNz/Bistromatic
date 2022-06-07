/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** Some usefull functions
*/

#include "my.h"

int cmp_gt(char const *s1, char const *s2)
{
    int i = 0;
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);

    if (len_s1 > len_s2)
        return (1);
    else if (len_s1 < len_s2)
        return (-1);
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    if (s1[i] == s2[i])
        return (0);
    else if (s1[i] > s2[i])
        return (1);
    else
        return (-1);
}

char *strip_zeros(char *str)
{
    int i = str[0] == '-' ? 1 : 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] != '0') {
            return (str);
        }
    }
    return ("0");
}

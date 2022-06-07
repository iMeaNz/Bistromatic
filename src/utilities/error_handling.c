/*
** EPITECH PROJECT, 2021
** Error Handling
** File description:
** error_handling
*/

#include "my.h"
#include <stdlib.h>

int same_char(char *base, char *operator)
{
    int error_detected = 0;
    char *temp = malloc(sizeof(char) * 2);
    temp[1] = '\0';

    for (int i = 0; i < my_strlen(base); i++) {
        temp[0] = base[i];
        if (my_strstr(operator, temp) != NULL)
            error_detected++;
    }
    for (int i = 0; i < my_strlen(operator); i++) {
        temp[0] = operator[i];
        if (my_strstr(base, temp) != NULL)
            error_detected++;
    }
    free(temp);
    return error_detected ? (84) : (0);
}

int duplicates_detector(char *string)
{
    int error_detected = 0;

    for (int i = 0; i < my_strlen(string) && !error_detected; i++)
        for (int j = i + 1; j < my_strlen(string) && !error_detected; j++)
            error_detected = string[i] == string[j];
    return error_detected ? (84) : (0);
}

int check_not_in(char *expression, char *base, char *operator)
{
    int error_detected = 0;
    char *tmp = malloc(sizeof(char) * 2);

    tmp[1] = '\0';
    for (int i = 0; i < my_strlen(expression); i++) {
        tmp[0] = expression[i];
        if (my_strstr(base, tmp) == NULL && my_strstr(operator, tmp) == NULL)
            error_detected++;
    }
    free(tmp);
    return error_detected ? (84) : (0);
}

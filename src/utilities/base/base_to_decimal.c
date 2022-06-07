/*
** EPITECH PROJECT, 2021
** BASE_TO_DECIMAL
** File description:
** Convert a number in a base in decimal
*/

#include "my.h"
#include <stdlib.h>

int is_operator_minus_plus(char c, char *operators);
int size_nbr(int nb);
int search_base(char *base_from, char to_search);
int find_sign_base(char *number, char *operators, int *nb_of_sign);
char *handle_sign(int sign, char *new_number);
char *str_initialize_alloc(char *input, int size);
char *my_mul(char *number1, char *number2);
char *my_add(char *a, char *b);
char *my_power_str(char *number, int power);

char *compute(int index, int *len, char *base_type_in_str, char *new_number)
{
    int size = size_nbr(index);
    char *index_in_str = malloc(sizeof(char) * size + 1);
    str_initialize_alloc(index_in_str, size + 1);
    my_putnbr_base_str(index, "0123456789", index_in_str);
    char *power = my_power_str(base_type_in_str, *(len) - 1);
    (*len)--;
    char *to_add = my_mul(index_in_str, power);
    char *tmp_res = my_add(new_number, to_add);
    free(power);
    free(to_add);
    free(new_number);
    free(index_in_str);
    return tmp_res;
}

char *my_getnbr_base_str(char *number, char *base_from, char *operators)
{
    int base_type = my_strlen(base_from);
    int nb_of_sign = 0;
    char *base_type_in_str = malloc(sizeof(char) * size_nbr(base_type) + 1);
    str_initialize_alloc(base_type_in_str, size_nbr(base_type) + 1);
    my_putnbr_base_str(base_type, "0123456789", base_type_in_str);
    int sign = find_sign_base(number, operators, &nb_of_sign);
    number = &number[nb_of_sign];
    int len = my_strlen(number);
    char *new_number = malloc(sizeof(char) * len + 1);
    str_initialize_alloc(new_number, len + 1);
    new_number[0] = '0';

    for (int i = 0; number[i] != '\0'; ++i) {
        int index = search_base(base_from, number[i]);
        new_number = compute(index, &len, base_type_in_str, new_number);
    }
    new_number = handle_sign(sign, new_number);
    free(base_type_in_str);
    return new_number;
}

char *base_to_decimal(char *nb, char *base_from, char *operators)
{
    return (my_getnbr_base_str(nb, base_from, operators));
}
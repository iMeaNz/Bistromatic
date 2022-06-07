/*
** EPITECH PROJECT, 2021
** UTILS_FOR_BASE_CLASSIC
** File description:
** Utils for base
*/

int is_op_minus_plus_base(char c, char *operators)
{
    if (c == operators[2] || c == operators[3])
        return 1;
    return 0;
}

int find_sign_base(char *number, char *operators, int *nb_of_sign)
{
    int nb_minus = 0;
    for (int i = 0; is_op_minus_plus_base(number[i], operators); ++i) {
        if (number[i] == operators[3]) {
            nb_minus++;
        }
        (*nb_of_sign)++;
    }
    if (nb_minus % 2 == 0) {
        return 1;
    } else {
        return -1;
    }
}
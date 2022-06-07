/*
** EPITECH PROJECT, 2021
** my_operators.c
** File description:
** my_operators
*/

#ifndef MY_OPERATORS_H_
    #define MY_OPERATORS_H_

    typedef struct operator_s {
        char *symbols;
        char *real_symbols;
        char *(*func)(char *a, char *b);
        int weight;
    } operator_t;

    char *my_mul(char *a, char *b);
    char *my_sub(char *a, char *b);
    char *my_add(char *a, char *b);
    char *my_div(char *a, char *b);
    char *my_mod(char *a, char *b);
    operator_t *get_op(operator_t *array, char *str);
    operator_t *get_real_op(operator_t *array, char *str);
#endif /* !MY_OPERATORS_H_ */

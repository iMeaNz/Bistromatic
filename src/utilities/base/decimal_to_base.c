/*
** EPITECH PROJECT, 2021
** DECIMAL_TO_BASE
** File description:
** Convert a decimal in a base
*/

#include "my.h"
#include "mylist.h"
#include <stdlib.h>

int stack_base_size(stack_base *begin);
int find_sign_decimal(char *number, int *nb_of_sign);
char *my_mod(char *a, char *b);
char *clean_zero_before(char *input);
void my_add_in_stack_base(stack_base **list, char *data);
int stack_base_size(stack_base *begin);
char *my_div(char *a, char *b);
int size_nbr(int nb);
char *str_initialize_alloc(char *input, int size);

char *compute_stack(stack_base *stack, char *base_to)
{
    int list_size = stack_base_size(stack);
    char *output = malloc(sizeof(char) * list_size + 1);
    int index = 0;
    stack_base *tmp = NULL;

    while (stack != NULL) {
        tmp = stack;
        if (stack->nbr[0] == '-')
            output[index++] = '-';
        else {
            int mod = my_getnbr(stack->nbr);
            free(stack->nbr);
            char to_push = base_to[mod];
            output[index++] = to_push;
        }
        stack = stack->next;
        free(tmp);
    }
    output[index] = '\0';
    return output;
}

char *push_in_stack(stack_base **stack, char *nb, char *len_base_in_str)
{
    char *remainder = my_mod(nb, len_base_in_str);
    char *to_push = clean_zero_before(remainder);
    my_add_in_stack_base(stack, to_push);
    char *tmp = nb;
    nb = my_div(tmp, len_base_in_str);
    return nb;
}

stack_base *fill_stack_nbr(char *nbr, char *base)
{
    stack_base *stack = NULL;
    int nb_of_sign = 0;
    int len_base = my_strlen(base);
    int size = size_nbr(len_base);
    char *len_base_in_str = malloc(sizeof(char) * size + 1);
    str_initialize_alloc(len_base_in_str, size + 1);
    my_putnbr_base_str(len_base, "0123456789", len_base_in_str);
    int sign = find_sign_decimal(nbr, &nb_of_sign);
    nbr = &nbr[nb_of_sign];

    if (nbr[0] == '0')
        push_in_stack(&stack, nbr, len_base_in_str);
    while (nbr[0] != '0') {
        nbr = push_in_stack(&stack, nbr, len_base_in_str);
    }
    free(len_base_in_str);
    if (sign == -1)
        my_add_in_stack_base(&stack, my_strdup("-"));
    return stack;
}

char *decimal_to_base(char *nb, char *base_to)
{
    stack_base *list = fill_stack_nbr(nb, base_to);
    char *output = compute_stack(list, base_to);
    return (output);
}

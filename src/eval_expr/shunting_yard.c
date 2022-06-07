/*
** EPITECH PROJECT, 2021
** shunting_yard.c
** File description:
** Implementation of the shunting yard algorithm in C
*/

#include <stdio.h>
#include "my.h"
#include "stack.h"
#include "queue.h"
#include "my_operators.h"
#include "bistromatic.h"
#include "base_operators.h"

char *my_slicenbr_base(char const *str, char *base, char *operators);
char *base_to_decimal(char *nb, char *base_from, char *operators);

void op_handle(queue_t *queue, stack_t *stack, char *current,
operator_t *operators)
{
    operator_t *op = get_op(operators, current);
    char *top = stack_peek(stack);
    operator_t *top_op = get_real_op(operators, top);
    int op_weight = op->weight;

    if (op_weight != 0) {
        while (top_op->weight >= op_weight
        && my_strlen(top) != 0) {
            stack_pop(stack);
            queue_add(queue, top_op->real_symbols);
            top = stack_peek(stack);
            top_op = get_real_op(operators, top);
        }
        stack_push(stack, op->real_symbols);
    }
}

int nb_handle(queue_t *queue, char const *str, int i, base_op_t *op)
{
    char *nbr = my_slicenbr_base(&str[i], op->base, op->operators);
    int len = my_strlen(nbr);
    char temp[2] = {0};

    if (i > 0 && (str[i] == op->operators[3] || str[i] == op->operators[2])) {
        temp[0] = str[i - 1];
        if (str[i - 1] == op->operators[OP_CLOSE_PARENT_IDX]
        || my_strstr(op->base, temp)) {
            free(nbr);
            return (0);
        }
    }
    if (len > 0) {
        queue_add(queue,
        base_to_decimal(nbr, op->base, op->operators));
        return (len);
    } else {
        free(nbr);
        return (0);
    }
}

void bracket_handle(queue_t *queue, stack_t *stack, char *current,
char **brackets)
{
    char *top = stack_peek(stack);

    if (my_strcmp(brackets[OP_OPEN_PARENT_IDX], current) == 0) {
        stack_push(stack, my_strdup(brackets[OP_OPEN_PARENT_IDX]));
    }
    if (my_strcmp(brackets[OP_CLOSE_PARENT_IDX], current) == 0) {
        while (my_strcmp(brackets[OP_OPEN_PARENT_IDX], top) != 0
        && top[0] != '\0') {
            queue_add(queue, stack_pop(stack));
            top = stack_peek(stack);
        }
        if (top[0] == '\0') {
            my_putstr(SYNTAX_ERROR_MSG);
            exit (84);
        }
        free(stack_pop(stack));
    }
}

void stack_to_queue(stack_t *stack, queue_t *queue)
{
    char *top = stack_peek(stack);

    while (my_strlen(top) != 0) {
        queue_add(queue, stack_pop(stack));
        top = stack_peek(stack);
    }
    stack_free(stack);
}

queue_t *shunting_yard(char const *str, operator_t *operators,
base_op_t *base_op, char **brackets)
{
    stack_t *stack = stack_create();
    queue_t *queue = queue_create();
    int i = 0;
    int nbr_len = 0;
    char current[2];
    current[1] = '\0';

    while (str[i] != '\0') {
        nbr_len = nb_handle(queue, str, i, base_op);
        if (nbr_len <= 0) {
            current[0] = str[i];
            op_handle(queue, stack, current, operators);
            bracket_handle(queue, stack, current, brackets);
            i++;
        } else
            i += nbr_len;
    }
    stack_to_queue(stack, queue);
    return (queue);
}

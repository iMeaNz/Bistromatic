/*
** EPITECH PROJECT, 2021
** eval_expr.c
** File description:
** eval_expr
*/

#include <stdio.h>
#include "my.h"
#include "queue.h"
#include "stack.h"
#include "my_operators.h"
#include "bistromatic.h"
#include "base_operators.h"

queue_t *shunting_yard(char const *str, operator_t *operators,
base_op_t *base_op, char **brackets);
stack_t *rpn(queue_t *queue, operator_t *operators_funcs);
char *format(char *str, char *signs);
char *clean_zero_before(char *input);
char *full_format(char *str, char *signs, char *base);
char *decimal_to_base(char *nb, char *base_to);

char *to_str(char c)
{
    char *new = malloc(sizeof(char) * 2);

    new[0] = c;
    new[1] = '\0';
    return (new);
}

void free_operators_str(operator_t *operators, char **brackets)
{
    for (int i = 0 ; operators[i].weight != 0 ; i++) {
        free(operators[i].symbols);
    }
    free(brackets[0]);
    free(brackets[1]);
}

char *compute_eval_expr(char *str, base_op_t *base_op, char **brackets,
operator_t *operators)
{
    char *result_str = NULL;
    char *result = NULL;
    char *format_str = full_format(str, base_op->operators, base_op->base);

    queue_t *result_queue = shunting_yard(format_str, operators,
    base_op, brackets);
    free(format_str);
    stack_t *result_stack = rpn(result_queue, operators);
    queue_free(result_queue);
    result_str = stack_pop(result_stack);
    if (stack_pop(result_stack) != NULL || result_str == NULL) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit (84);
    }
    result = clean_zero_before(result_str);
    stack_free(result_stack);
    free_operators_str(operators, brackets);
    return (result);
}

char *eval_expr(char *base, char *op_str, char *str)
{
    char *result = NULL;
    char *converted_str = NULL;
    operator_t operators[] = {{to_str(op_str[OP_PLUS_IDX]), "+", &my_add, 1},
        {to_str(op_str[OP_SUB_IDX]), "-", &my_sub, 1},
        {to_str(op_str[OP_MULT_IDX]), "*", &my_mul, 2},
        {to_str(op_str[OP_DIV_IDX]), "/", &my_div, 2},
        {to_str(op_str[OP_MOD_IDX]), "%", &my_mod, 2},
        {"", "", NULL, 0},
    };
    char *brackets[] = {to_str(op_str[OP_OPEN_PARENT_IDX]),
    to_str(op_str[OP_CLOSE_PARENT_IDX])};
    base_op_t *base_op = malloc(sizeof(base_op_t));

    base_op->base = base;
    base_op->operators = op_str;
    result = compute_eval_expr(str, base_op, brackets, operators);
    converted_str = decimal_to_base(result, base);
    free(result);
    return (converted_str);
}

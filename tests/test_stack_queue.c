/*
** EPITECH PROJECT, 2021
** test_add_sub.c
** File description:
** test_add_sub
*/

#include <criterion/criterion.h>
#include "my.h"
#include "queue.h"
#include "stack.h"
#include "unistd.h"

int eval_expr(char const *str);

Test(stack, stack_free)
{
    stack_t *stack = stack_create();

    stack_push(stack, "test");
    stack_free(stack);
}

Test(stack, stack_pop)
{
    stack_t *stack = stack_create();

    cr_assert(stack_pop(stack) == NULL);
}

Test(queue, queue_free)
{
    queue_t *queue = queue_create();

    queue_add(queue, "test");
    queue_free(queue);
}

Test(queue, queue_pop)
{
    queue_t *queue = queue_create();

    cr_assert(queue_pop(queue) == NULL);
}

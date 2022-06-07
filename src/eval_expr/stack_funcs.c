/*
** EPITECH PROJECT, 2021
** stack_funcs.c
** File description:
** stack_funcs
*/

#include "stack.h"
#include "mylist.h"
#include <unistd.h>
#include <stdlib.h>

void stack_push(stack_t *stack, char *value)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));

    new->data = value;
    new->next = stack->list_head;
    stack->list_head = new;
}

void stack_free(stack_t *stack)
{
    linked_list_t *current = stack->list_head;
    linked_list_t *to_free = NULL;

    while (current != NULL) {
        to_free = current;
        current = current->next;
        free(to_free);
    }
    free(stack);
}

char *stack_pop(stack_t *stack)
{
    char *return_str = NULL;
    linked_list_t *head = stack->list_head;
    linked_list_t *to_free = head;

    if (to_free != NULL) {
        return_str = head->data;
        stack->list_head = head->next;
        free(to_free);
    }
    return (return_str);
}

stack_t *stack_create(void)
{
    stack_t *new = malloc(sizeof(stack_t));
    linked_list_t *list = NULL;

    new->list_head = list;
    return (new);
}

char *stack_peek(stack_t *stack)
{
    linked_list_t *head = stack->list_head;

    if (head != NULL)
        return (head->data);
    return ("");
}

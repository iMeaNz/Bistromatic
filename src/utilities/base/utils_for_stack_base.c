/*
** EPITECH PROJECT, 2021
** UTILS FOR STACK BASE
** File description:
** Utilitary function for the linked list stack base
*/

#include "my.h"
#include "mylist.h"

void my_add_in_stack_base(stack_base **list, char *data)
{
    stack_base *element;

    element = (stack_base *)malloc(sizeof(*element));
    element->nbr = data;
    element->next = *list;
    *list = element;
}

int stack_base_size(stack_base *begin)
{
    stack_base *tmp;
    int size = 0;

    tmp = begin;
    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    return (size);
}

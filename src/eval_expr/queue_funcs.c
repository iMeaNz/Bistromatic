/*
** EPITECH PROJECT, 2021
** queue_funcs.c
** File description:
** queue_funcs
*/

#include "queue.h"
#include "mylist.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>

void queue_add(queue_t *queue, char *value)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));
    linked_list_t *current = queue->list_head;

    new->data = value;
    new->next = NULL;
    if (current == NULL)
        queue->list_head = new;
    else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }
}

void queue_free(queue_t *queue)
{
    linked_list_t *current = queue->list_head;
    linked_list_t *to_free = NULL;

    while (current != NULL) {
        to_free = current;
        current = current->next;
        free(to_free);
    }
    free(queue);
}

char *queue_pop(queue_t *queue)
{
    char *return_str = NULL;
    linked_list_t *head = queue->list_head;
    linked_list_t *to_free = head;

    if (to_free != NULL) {
        return_str = head->data;
        queue->list_head = head->next;
        free(to_free);
    }
    return (return_str);
}

queue_t *queue_create(void)
{
    queue_t *new = malloc(sizeof(queue_t));
    linked_list_t *list = NULL;

    new->list_head = list;
    return (new);
}

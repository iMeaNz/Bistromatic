/*
** EPITECH PROJECT, 2021
** queue.h
** File description:
** queue
*/

#ifndef QUEUE_H_
    #define QUEUE_H_

    #include "mylist.h"

    typedef struct queue_s {
        linked_list_t *list_head;
    } queue_t;

#endif /* !QUEUE_H_ */

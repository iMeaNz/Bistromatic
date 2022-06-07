/*
** EPITECH PROJECT, 2021
** mylist.h
** File description:
** mylist
*/

#ifndef MYLIST_H_H
    #define MYLIST_H_H

    typedef struct linked_list_s {
        void *data;
        struct linked_list_s *next;
    } linked_list_t;

    typedef struct linked_list_stack_base {
        char *nbr;
        struct linked_list_stack_base *next;
    } stack_base;

#endif /* !MYLIST_H_H */

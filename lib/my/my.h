/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdlib.h>
    #include <unistd.h>
    #include "stack.h"
    #include "queue.h"
    int check_overflow(long nb);
    char *concat_params(int argc, char **argv);
    char *my_putnbr_base_str(int nbr, char const *base, char *str);
    char *convert_base(char *nbr, char const *base_from, char const *base_to);
    int my_compute_power_rec(int nb, int p);
    int my_compute_square_root(int nb);
    int my_find_prime_sup(int nb);
    int my_getnbr_base(char const *str, char const *base);
    int my_getnbr(char const *str);
    int my_is_prime(int nb);
    int my_isneg(int n);
    int my_put_nbr(int nb);
    void my_putchar(int c);
    int my_putnbr_base(int nbr, char const *base);
    int my_putstr(char const *str);
    char *my_revstr(char *str);
    int my_show_word_array(char * const *tab);
    int my_showmem(char const *str, int size);
    int my_showstr(char const *str);
    void my_sort_int_array(int *array, int size);
    int my_str_isalpha(char const *str);
    int my_str_islower(char const *str);
    int my_str_isnum(char const *str);
    int my_str_isprintable(char const *str);
    int my_str_isupper(char const *str);
    char **my_str_to_word_array(char const *str);
    char *my_strcapitalize(char *str);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    int my_strlen(char const *str);
    char *my_strlowcase(char *str);
    char *my_strncat(char *dest, char const *src, int nb);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strstr(char *str, char const *to_find);
    char *my_strupcase(char *str);
    void my_swap(int *a, int *b);
    int power(int nb, int power);
    int get_color(unsigned char red, unsigned char green, unsigned char blue);
    int swap_endian_color(int color);
    void stack_push(stack_t *stack, char *value);
    void stack_free(stack_t *stack);
    char *stack_pop(stack_t *stack);
    stack_t *stack_create(void);
    char *stack_peek(stack_t *stack);
    void queue_add(queue_t *queue, char *value);
    void queue_free(queue_t *queue);
    char *queue_pop(queue_t *queue);
    queue_t *queue_create(void);
#endif /* !MY_H_ */

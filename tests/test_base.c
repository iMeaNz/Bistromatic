/*
** EPITECH PROJECT, 2021
** TEST_BASE
** File description:
** Tests for the base functions
*/

#include <criterion/criterion.h>
#include "my.h"

char *decimal_to_base(char *nb, char *base_to);
int search_base(char *base_from, char to_search);
char *eval_expr(char *base, char *op, char *str);

Test(search_base, search_base_tests)
{
    cr_assert_eq(search_base("0123456789ABCDEF", '2'), 2);
    cr_assert_eq(search_base("01", '1'), 1);
    cr_assert_eq(search_base("01", '2'), -1);
}

Test(decimal_to_base, decimal_to_base_classic)
{
    cr_assert_str_eq(decimal_to_base("123", "0123456789ABCDEF"),
    "7B");
    cr_assert_str_eq(decimal_to_base("123", "01"),
    "1111011");
}

Test(eval_expr, binary_base)
{
    cr_assert_str_eq(eval_expr("01", "()+-*/%",
    "--00000001+1"),
    "10");
}

Test(eval_expr, special_nb_op)
{
    cr_assert_str_eq(eval_expr("ABC", "0123456",
    "B2B"),
    "C");
}

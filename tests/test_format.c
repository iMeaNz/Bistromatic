/*
** EPITECH PROJECT, 2021
** test_add_sub.c
** File description:
** test_add_sub
*/

#include <criterion/criterion.h>
#include "my.h"

char *format(char *str, char *signs, char *base);
char *remove_signs(char *input, char *signs);

Test(format, removing_minus_plus_before_parenthesis)
{
    cr_assert_str_eq(format("-(-5+4)*-(5)-(5/4)", "()+-*/%", "0123456789"),
    "-1*(-5+4)*-1*(5)-1*(5/4)");
    cr_assert_str_eq(format("-(-5+4)*-(5)+(5/4)", "()+-*/%", "0123456789"),
    "-1*(-5+4)*-1*(5)+1*(5/4)");
    cr_assert_str_eq(format("+(-5+4)*-(5)+(5/4)", "()+-*/%", "0123456789"),
    "+1*(-5+4)*-1*(5)+1*(5/4)");
}

Test(format, remove_useless_signs)
{
    cr_assert_str_eq(remove_signs("-----++-5*--(4+1)-+10", "()+-*/%"),
    "+5*+(4+1)-10");
}

Test(format, mixed_format_remove_signs)
{
    char *removed_signs = remove_signs("-----++-5*--(4+1)-+10", "()+-*/%");
    cr_assert_str_eq(format(removed_signs, "()+-*/%", "0123456789"),
    "+5*+1*(4+1)-10");
}


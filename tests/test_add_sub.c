/*
** EPITECH PROJECT, 2021
** test_add_sub.c
** File description:
** test_add_sub
*/

#include <criterion/criterion.h>
#include "my.h"

char *my_add(char *a, char *b);

Test(main_test, inf_add_sub1)
{
    char *a = my_strdup("-876435");
    char *b = my_strdup("-987143265");
    char *result = my_add(a, b);
    cr_assert_str_eq(result, "-988019700");
    free(result);
    free(a);
    free(b);
}

Test(main_test, inf_add_sub2)
{
    char *a = my_strdup("-807965");
    char *b = my_strdup("34532");
    char *result = my_add(a, b);
    cr_assert_str_eq(result, "-773433");
    free(result);
    free(a);
    free(b);
}

Test(main_test, inf_add_sub3)
{
    char *a = my_strdup("435439435845843984358439");
    char *b = my_strdup("45359766785665822182412343254343435433339459569");
    char *result = my_add(a, b);
    cr_assert_str_eq(result,
    "45359766785665822182412778693779281277323818008");
    free(result);
    free(a);
    free(b);
}

Test(main_test, inf_add_sub4)
{
    char *a = my_strdup("1234567");
    char *b = my_strdup("-123456789");
    char *result = my_add(a, b);
    cr_assert_str_eq(result, "-122222222");
    free(result);
    free(a);
    free(b);
}
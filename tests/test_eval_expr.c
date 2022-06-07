/*
** EPITECH PROJECT, 2021
** test_add_sub.c
** File description:
** test_add_sub
*/

#include <criterion/criterion.h>
#include "my.h"

char *eval_expr(char *base, char *op, char *str);

Test(eval_expr, positive_int)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "1+1+1+1+1+1+1+1+1+1+1+10000+123+456"), "10590");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "10230+(12882+1313)+(122+232)"), "24779");
}

Test(eval_expr, parentheses_hell)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "((((((1+1000+2+3))))))"), "1006");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "((((10230)))+(((12882+1313)+(122+232))))"), "24779");
}

Test(eval_expr, negative_int)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "-18323+780-6789+(1387-178)-26+23-(-623)"), "-22503");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "((-18323)+(780-6789)+(1387-178)-26+23-(-623))"), "-22503");
}

Test(eval_expr, mul_div_mod)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "1762*323-1239+239%(232+1)/2+4"), "567894");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "((1762*323)-(1239+23389)%(232+1)/2+(4))"), "569049");
}

Test(eval_expr, zeros)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "0+00000+000+0+0+0+0+0+0+0+0+0+0-0-(-0)"), "0");
}

Test(eval_expr, multiple_plus)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "1+1+1++1+1+1++1+1+1+1+1+10000++123+456"), "10590");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "10230+(12882+1313)+(122++232)"), "24779");
}

Test(eval_expr, mult)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "5678954*45678909634789202"),
    "259408426586124677854708");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "5678954*45678909634789202*80008932*6286782368768*12"),
    "1565785350086507363918097387775090308629200896");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "-12*12"), "-144");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "4576689782769*273767678233*-2536233823*280382389*-23798287*2*1*1*1"),
    "42408153582481385407294499723703570569781827298906");
}

Test(eval_expr, bistro_pdf)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "6/(12+14%(30%5+(10*25)-46)+16)-20"),
    "-20");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*\
    (-(12-98*42)*(16+63-50/3))"),
    "-744629760");
}

Test(eval_expr, modulo)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "30%5"),
    "0");
}

Test(eval_expr, division)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "(6/(12+14%(30%5+(10*25)-46)+16)-20)/43"),
    "0");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%",
    "((13+15/5*(6*(12+14*(30*5+(10*25)-46)+16)-20)*43))"),
    "3855049");
}

Test(eval_expr, division_with_neg)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "5/-5"), "-1");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-5/5"), "-1");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-5/-5"), "1");
}

Test(eval_expr, modulo_with_neg)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "5%-4"), "1");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-5%4"), "-1");
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-5%-4"), "-1");
}


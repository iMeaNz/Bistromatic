/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** formatting str
*/

#include "bistromatic.h"
#include "my.h"

char *remove_signs(char *input, char *signs)
{
    char *out = malloc(sizeof(char) * my_strlen(input) + 1);
    int index = 0;
    int detected = 0;
    int counter = 0;

    for (int i = 0; i < my_strlen(input); i++) {
        if (input[i] == signs[OP_SUB_IDX] || input[i] == signs[OP_PLUS_IDX]) {
            detected = 1;
            input[i] == signs[OP_SUB_IDX] ? counter++ : i;
        } else if (detected) {
            out[index++] = counter % 2 == 0 ? signs[2] : signs[3];
            out[index] = input[i];
            counter = 0;
            detected = 0;
        } else
            out[index] = input[i];
        index += detected ? 0 : 1;
    }
    out[index] = '\0';
    return (out);
}

int format_counter(char *str, char *signs)
{
    int counter = 0;

    for (int i = 0; i < my_strlen(str); i++)
        if ((str[i] == signs[OP_SUB_IDX] || str[i] == signs[OP_PLUS_IDX])
        && str[i + 1] == signs[0])
            counter += 3;
        else
            counter++;
    return (counter);
}

char *format(char *str, char *signs, char *base)
{
    int size = format_counter(str, signs);
    int nb_pos = my_strlen(base) > 1;
    char *output = malloc(sizeof(char) * (size + 1));
    int output_index = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if ((str[i] == signs[OP_SUB_IDX] || str[i] == signs[OP_PLUS_IDX])
        && str[i + 1] == signs[0]) {
            output[output_index] = str[i];
            output[++output_index] = base[nb_pos];
            output[++output_index] = signs[OP_MULT_IDX];
            output[++output_index] = signs[OP_OPEN_PARENT_IDX];
            i++;
        } else
            output[output_index] = str[i];
        output_index++;
    }
    output[output_index] = '\0';
    return (output);
}

char *full_format(char *str, char *signs, char *base)
{
    char *removed_signs = remove_signs(str, signs);
    char *result = format(removed_signs, signs, base);

    free(removed_signs);
    return (result);
}
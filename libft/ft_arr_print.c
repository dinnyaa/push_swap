#include "libft.h"

void ft_arr_print(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        ft_putchar_fd(48 + (arr[i]), 1);
        i++;
    }
}


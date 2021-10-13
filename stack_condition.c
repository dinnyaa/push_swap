#include "push_swap.h"

int max_index(t_stack stack)
{
    int i;
    int max;

    i = 0;
    max = 0;
    while (i < stack.size)
    {
        if (stack.arr[i] > stack.arr[max])
            max = i;
        i++;
    }
    return (max);
}

int min_index(t_stack stack)
{
    int i;
    int min;

    i = 0;
    min = 0;
    while (i < stack.size)
    {
        if (stack.arr[i] < stack.arr[min])
            min = i;
        i++;
    }
    return (min);
}

int is_sorted(t_stack a)
{
	int i;

	i = 0;
	while (i < (a.size - 1))
	{
		if (a.arr[i] < a.arr[i + 1])
			i++;
		else 
			return (0);
	}
	return (1);
}

void print_stacks(t_stack a, t_stack b)
{
	int i = 0;
	int j = 0;

	int tmp_size = (a.size > b. size) ? a.size : b.size;
	if (a.arr || b.arr)
	{
		while (tmp_size--)
		{
			if (i < a.size)
			{
				ft_putnbr_fd(a.arr[i], 1);
				ft_putchar_fd('\t', 1);
			}
			else
				ft_putchar_fd('\t', 1);
			if (j < b.size)
			{
				ft_putnbr_fd(b.arr[j], 1);
				ft_putchar_fd('\n', 1);
			}
			else
				ft_putchar_fd('\n', 1);
			i++;
			j++;
		}
		ft_putstr_fd("-\t-\nA\tB\n\n", 1);

	}
	else
		ft_putendl_fd("stacks are empty", 1);
}

void free_stack(t_stack *stack)
{
    free(stack->arr);
    free(stack->boolean);
}
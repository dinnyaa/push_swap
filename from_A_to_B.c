#include "push_swap.h"

int count_true(int *arr, t_stack stack)
{
    int i = 0;
    int count = 0;
    while (i < stack.size)
    {
        if (arr[i] == 1)
            count++;
        i++;
    }
    return (count);
}

static  int sa_needed(t_stack a)
{
    int before;
    int after;
    before = count_true(a.boolean, a);
    ft_swap(&a.arr[0], &a.arr[1]);
    a.boolean = markup(a);

    after = count_true(a.boolean, a);
    ft_swap(&a.arr[0], &a.arr[1]);
    a.boolean = markup(a);
    return (after > before);
}

void from_A_to_B(t_stack *a, t_stack *b)
{
    int false_count = a->size - count_true(a->boolean, *a);

    while (false_count)
    {
        if (sa_needed(*a))
           sa(a);
        else if (a->boolean[0] == 0)
            pb(a, b);
        else
            ra(a);     
        false_count = a->size - count_true(a->boolean, *a);
    }
}


#include "push_swap.h"

static void sort_two(t_stack *a)
{
     if (a->size == 2)
             sa(a);
}

static void sort_three(t_stack *a)
{
    int max_i = max_index(*a);
    int min_i = min_index(*a);

    if (a->size == 3)
    {
        if (max_i == 2 && min_i == 1)           
            sa(a);
        else if (max_i == 0 && min_i == 2)      
        {
            sa(a);
            rra(a);
        }
        else if (max_i == 0 && min_i == 1)      
            ra(a);
        else if (max_i == 1 && min_i == 0)      
        {
            sa(a);
            ra(a);
        }
        else if (max_i == 1 && min_i == 2)
            rra(a);
    }
}

static void sort_five(t_stack *a, t_stack *b)
{
    if (a->size == 4 || a->size == 5)
    {
        while (a->size > 3)
        {
            int min_i = min_index(*a);
            if ((a->size)/2 < min_i)
                rra(a);
            else
                ra(a);
            if (min_index(*a) == 0)
                pb(a, b);
        }
        sort_three(a);
        while (b->size)
           pa(a, b);
    }
       
}

void easy_sorting(t_stack *a, t_stack *b)
{
    if (!is_sorted(*a))
    {
        sort_two(a);
        sort_three(a);
        sort_five(a, b);
    }
}
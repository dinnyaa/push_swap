#include "push_swap.h"

static int find_nearest(t_stack stack, int item, int diff)
{
    int i = 0;
    int rtn = 0;
    int max = max_index(stack);
    if (diff == item)
        return (min_index(stack));
    if (item > stack.arr[max])
        return max + 1;
    while (i < (stack.size))
    {
        if ((stack.arr[i] - item) < diff && (stack.arr[i] - item) > 0)
        {
            diff = stack.arr[i] - item;
            rtn = i;
        }
        i++;
    }
    return (rtn);
}

static t_steps *count_steps(t_stack a, t_stack b)
{
    int i = 0;
    int nearest = 0;
    t_steps *steps;
    steps = malloc(b.size * sizeof(t_steps));    
    while (i < b.size)
    {
        if (i <= b.size/2)
        {
            steps[i].from_B = i;
            steps[i].shiftup_B = 1;
        }
        else
        {
            steps[i].from_B = b.size - i;
            steps[i].shiftup_B = 0;
        }
        nearest = find_nearest(a, b.arr[i], a.size + b.size - 1);
        if (nearest <= a.size/2)
        {
            steps[i].from_A = nearest;
            steps[i].shiftup_A = 1;
        }
        else
        {
            steps[i].from_A = a.size - nearest;
            steps[i].shiftup_A = 0;
        }
        steps[i].total  = steps[i].from_A + steps[i].from_B;
        i++;     
    }
    return (steps);
}

static int choose_step(t_stack *b, t_steps *steps)
{
    int i = 0;
    int min = 0;

    while (i < b->size)
    {
        if (steps[i].total < steps[min].total)
            min = i;
        i++;
    }
    return (min);
}

void push(t_stack *a, t_stack *b, t_steps steps)
{
    int i = 0;
    int j = 0;
    if (steps.shiftup_A && steps.shiftup_B)
    {
        while (i < steps.from_A && j < steps.from_B)
        {
            rr(a, b);
            i++;
            j++;
        }
        while (i < steps.from_A)
        {
            ra(a);
            i++;
        }
        while (j < steps.from_B)
        {
            rb(b);
            j++;
        }
    }
    else if (!steps.shiftup_A && !steps.shiftup_B)
    {
        while (i < steps.from_A && j < steps.from_B)
        {
            rrr(a, b);
            i++;
            j++;
        }
        while (i < steps.from_A)
        {
            rra(a);
            i++;
        }
        while (j < steps.from_B)
        {
            rrb(b);
            j++;
        }
    }
    else if (!steps.shiftup_A && steps.shiftup_B)
    {
        while (i < steps.from_A)
        {
            rra(a);
            i++;
        }
        while (j < steps.from_B)
        {
            rb(b);
            j++;
        }
    }
    else if (steps.shiftup_A && !steps.shiftup_B)
    {
        while (i < steps.from_A)
        {
            ra(a);
            i++;
        }
        while (j < steps.from_B)
        {
            rrb(b);
            j++;
        }
    }
    pa(a, b);

}
 void from_B_to_A(t_stack *a, t_stack *b)
{
    t_steps *steps = NULL;
    int i;
    int j = 0;
    while (b->size)
    {
        steps = count_steps(*a, *b);
        i = choose_step(b, steps);
        push(a, b, steps[i]);
        j++;
        free(steps);
    }
}

void align_stack(t_stack *stack)
{
    int min = min_index(*stack);
    while (!is_sorted(*stack))
    {
        if (min < stack->size/2)
            ra(stack);
        else
            rra(stack);
    }
}
void sorting(t_stack *a, t_stack *b)
{
    if (a->size >= 6)
    {
        from_A_to_B(a, b);
        from_B_to_A(a, b);
        align_stack(a);
    }
}

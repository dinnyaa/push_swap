#include "push_swap.h"

void shift_right(t_stack *stack)
{
	int tmp;
	int tmp_bool;
	int i = stack->size - 1;
   
	tmp = stack->arr[stack->size - 1];
	tmp_bool = stack->boolean[stack->size - 1];
	while (i)
	{
	   stack->arr[i] = stack->arr[i - 1];
	   stack->boolean[i] = stack->boolean[i - 1];
	   i--;
	}
	stack->arr[0] = tmp;  
	stack->boolean[0] = tmp_bool;
}

void rra(t_stack *a)
{
	if (a->arr)
	{
		shift_right(a);
		ft_putendl_fd("rra", 1); 
	}
}

void rrb(t_stack *b)
{
	if (b->arr)
	{
		shift_right(b);
		ft_putendl_fd("rrb", 1); 
	}
}

void rrr(t_stack *a, t_stack *b)
{
	if (a->arr && b->arr)
	{
		shift_right(a);
		shift_right(b);
		ft_putendl_fd("rrr", 1); 
	}
}

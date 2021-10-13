#include "push_swap.h"
 
void shift_left(t_stack *stack)
{
   int tmp;
   int tmp_bool;
   int i = 0;
    
	 tmp = stack->arr[0];
	 tmp_bool = stack->boolean[0];       
	   while (i < (stack->size - 1))
	   {
		 stack->arr[i] = stack->arr[i + 1];
		 stack->boolean[i] = stack->boolean[i + 1];
		 i++;
	   }
	   stack->arr[i] = tmp;
	   stack->boolean[i] = tmp_bool;
}

void ra(t_stack *a)
{
	if (a->arr)
	{
		shift_left(a);
		ft_putendl_fd("ra", 1); 
	}
}

void rb(t_stack *b)
{
	if (b->arr)
	{
		shift_left(b);
		ft_putendl_fd("rb", 1); 
	}
}

void rr(t_stack *a, t_stack *b)
{
	if (a->arr && b->arr)
	{
		shift_left(a);
		shift_left(b);
		ft_putendl_fd("rr", 1); 
	}
}
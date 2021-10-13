#include "push_swap.h"

void sa(t_stack *a)
{
	if (a->arr)
	{
		ft_swap(&a->arr[0], &a->arr[1]);
		a->boolean = markup(*a);
		ft_putendl_fd("sa", 1); 
	}
}

void sb(t_stack *b)
{
	if (b->arr)
	{
		ft_swap(&b->arr[0], &b->arr[1]);
		b->boolean = markup(*b);
		ft_putendl_fd("sb", 1); 
	}
}

void ss(t_stack *a, t_stack *b)
{
	if (a->arr && b->arr)
	{
		ft_swap(&a->arr[0], &a->arr[1]);
		ft_swap(&b->arr[0], &b->arr[1]);
		a->boolean = markup(*a);
		b->boolean = markup(*b);
		ft_putendl_fd("ss", 1);
	}
}
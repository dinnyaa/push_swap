#include "push_swap.h"

static int *push_to(int *arr, int num, int size)
{
	int *newarr;
	int i;
	
	i = 0;
	newarr = (int*)malloc(sizeof(int) * (size + 1));
	newarr[i] = num;
	while (i < size)
	{
		newarr[i + 1] = arr[i];
		i++;
	}
	if (arr)
		free(arr);
	return (newarr);  
}

static int *pop_from(int *arr, int size)
{
	int *newarr;
	int i;

	i = 0;
	newarr = (int*)malloc(sizeof(int) * (size - 1));
	while (i < size - 1)
	{
		newarr[i] = arr[i + 1];
		i++;
	}
	if (arr)
		free(arr);
	return (newarr);  
}

void pop_push(t_stack *s1, t_stack *s2)
{
	s1->arr = push_to(s1->arr, *(s2->arr), s1->size);
	s1->boolean = push_to(s1->boolean, *(s2->boolean), s1->size);
	s1->size++;
	s2->arr = pop_from(s2->arr, s2->size);
	s2->boolean = pop_from(s2->boolean, s2->size);
	s2->size--;
}

void pa(t_stack *a, t_stack *b)
{
	if (b->arr)
	{
		pop_push(a, b);
		ft_putendl_fd("pa", 1); 
	}
}

void pb(t_stack *a, t_stack *b)
{
	if (a->arr)
	{
		pop_push(b, a);
		ft_putendl_fd("pb", 1);  
	}
}

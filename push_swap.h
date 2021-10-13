#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

typedef struct s_stack
{
	int			size;
	int			*boolean;
	int			*arr;
}             	t_stack;

typedef	struct	s_steps
{
	int			from_A;
	int			from_B;
	int			shiftup_A;
	int			shiftup_B;
	int			total;
}				t_steps;

t_stack init_stack();
t_stack fill_stack(int size, char **str);
void indexed(t_stack *stack);
t_stack parsing(int argc, char **argv);
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void shift_right(t_stack *stack);
void shift_left(t_stack *stack);
void pop_push(t_stack *s1, t_stack *s2);
int is_sorted(t_stack a);
int min_index(t_stack stack);
int max_index(t_stack stack);
void print_stacks(t_stack a, t_stack b);
void easy_sorting(t_stack *a, t_stack *b);
void from_A_to_B(t_stack *a, t_stack *b);
void from_B_to_A(t_stack *a, t_stack *b);
void sorting(t_stack *a, t_stack *b);
int count_true(int *arr, t_stack stack);
int *markup(t_stack stack);
void free_stack(t_stack *stack);

#endif
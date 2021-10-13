#include "push_swap.h"

void do_op(t_stack *a, t_stack *b, char* op)
{
    if (!ft_strncmp("sa", op, ft_strlen(op)))
        ft_swap(&a->arr[0], &a->arr[1]);
    else if (!ft_strncmp("sb", op, ft_strlen(op)))
        ft_swap(&b->arr[0], &b->arr[1]);
    else if (!ft_strncmp("ss", op, ft_strlen(op)))
    {
        ft_swap(&a->arr[0], &a->arr[1]);
        ft_swap(&b->arr[0], &b->arr[1]);
    }
    else if (!ft_strncmp("pa", op, ft_strlen(op)))
        pop_push(a, b);
    else if (!ft_strncmp("pb", op, ft_strlen(op)))
        pop_push(b, a); 
    else if (!ft_strncmp("ra", op, ft_strlen(op)))
        shift_left(a);
    else if (!ft_strncmp("rb", op, ft_strlen(op)))
        shift_left(b);
    else if (!ft_strncmp("rr", op, ft_strlen(op)))
    {
        shift_left(a);
        shift_left(b);
    }
     else if (!ft_strncmp("rra", op, ft_strlen(op)))
        shift_right(a);
    else if (!ft_strncmp("rrb", op, ft_strlen(op)))
        shift_right(b);
    else if (!ft_strncmp("rrr", op, ft_strlen(op)))
    {
        shift_right(a);
        shift_right(b);
    }
    else
        ft_error("Error");
}

int read_line(t_stack *a, t_stack *b)
{
    char *op;

    if (is_sorted(*a))
        return (1);
    while (get_next_line(0, &op))
        do_op(a, b, op);
    if (is_sorted(*a) && b->size == 0)
        return (1);
    return (0);
}
int main(int argc, char **argv)
{
    int rtn;
    t_stack a = init_stack();
    t_stack b = init_stack();

    a = parsing(argc, argv);
    rtn = read_line(&a, &b);
    if (rtn == 1)
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);
    free_stack(&a);
	free_stack(&b);
	return (0);
}
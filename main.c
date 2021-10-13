#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack a = init_stack();
	t_stack b = init_stack();

	a = parsing(argc, argv);
	easy_sorting(&a, &b);
	sorting(&a,&b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
#include "push_swap.h"

t_stack    init_stack()
{
	t_stack stack;

	stack.size = 0;
	stack.boolean = NULL;
	stack.arr = NULL;
	return (stack);
}

static int *fill_arr(int size, char **str)
{
	int i = 0;
	int *arr;

	arr = (int*)malloc(size * sizeof(int *));
	while (i < size)
	{
		arr[i] = ft_atoi(str[i]);
		i++;
	}
	return (arr);
}

static int *rtn(int **matrix, t_stack stack)
{
    int max_count = 0;
    int i = 0;
    int head = 0;
	int *rtn;

    while (i < stack.size)
    {
        if (max_count <= count_true(matrix[i], stack))
        {
            max_count = count_true(matrix[i], stack);
            head = (stack.arr[head] < stack.arr[i]) ? head : i;
        }
        i++;
    }
	rtn = ft_num_dup(matrix[head], stack.size);
	ft_free_matrix(matrix, stack.size);
    return (rtn);
}

int *markup(t_stack stack)
{
    int j = 0;
    int i = 0;
    int tmp_max;
    int **matrix;

	matrix = (int**)malloc(stack.size * sizeof(int*));
    while (i < stack.size)
        matrix[i++] = (int*)ft_calloc(stack.size, sizeof(int));

    while (j < stack.size)
    {
        i = j;
        tmp_max = stack.arr[j];
        while (i < (stack.size))
        {
            if (stack.arr[i] >= tmp_max)
            {
                tmp_max = stack.arr[i];
                matrix[j][i] = 1;
            }
            i++;
        }
        j++;
    }
    return (rtn(matrix, stack));
}

t_stack fill_stack(int size, char **str)
{
	t_stack stack;

	stack.size = size;
	stack.arr = fill_arr(size, &*str);
	stack.boolean = markup(stack);
	return (stack);
}
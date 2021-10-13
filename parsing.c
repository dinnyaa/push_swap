#include "push_swap.h"

static void is_num(char **argv)
{
	int i;
	int j = 0;

	while (argv[j] != '\0')
	{
		i = 0;
		if (argv[j][i] == '+' || argv[j][i] == '-')
			i++;
		while (argv[j][i] != '\0')
		{
			if (!ft_isdigit(argv[j][i]))
				ft_error("Error");
			i++;
		}
		j++;
	}
}
static void has_duplicate(int arr[], int size)
{
	int i;
	int j;

	i = 0;
	while(i < size)
	{
		
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			ft_error("Error");
			j++;
		}
		i++;
	}
}

static int		count(char  **str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;

	return (i);
}

t_stack parsing(int argc, char **argv)
{
	t_stack tmp;

	if (argc == 1)
		exit(0);
	else if (argc == 2)
	{
		char **str;
		str = ft_split(argv[1], ' ');
		is_num(str);
		tmp = fill_stack(count(str), str); 
		ft_free_str((void**)str);
	}
	else if (argc > 2)
	{
		++argv;       
		is_num(argv);
		tmp = fill_stack(argc - 1, argv);
	}
	indexed(&tmp);
	has_duplicate(tmp.arr, tmp.size);
	return tmp;
}
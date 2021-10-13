#include "libft.h"

void ft_free_str(void **str)
{
	int j = 0;
	while (str[j] != '\0')
	{
		free(str[j]);
		j++;
	}
	free(str);
}
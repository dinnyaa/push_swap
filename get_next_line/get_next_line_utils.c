/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:34:10 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/04/15 20:54:56 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	int		s1_size;
	int		s2_size;

	if (!s1 && !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) *
					(s1_size + s2_size + 1))))
		return (NULL);
	ft_memmove(str, s1, s1_size);
	ft_memmove(str + s1_size, s2, s2_size);
	*(str + s1_size + s2_size) = '\0';
	free(s1);
	return (str);
}

char	*move_ptr(char *str)
{
	char	*result;
	int		i;
	int		j;
	int		res_len;

	j = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	res_len = ft_strlen(str) - i;
	if (!(result = malloc(res_len + 1)))
		return (NULL);
	i++;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*ft_new_str(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!(new_str = malloc(i + 1)))
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:43:01 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/04/15 20:50:51 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
#include "../libft/libft.h"

#define BUFFER_SIZE 1

int		get_next_line(const int fd, char **line);
int		is_new_line(char *str);
char	*ft_join(char *s1, char *s2);
char	*ft_new_str(char *str);
char	*move_ptr(char *str);

#endif

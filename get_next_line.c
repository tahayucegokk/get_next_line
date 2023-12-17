/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 06:47:18 by muyucego          #+#    #+#             */
/*   Updated: 2023/12/17 07:25:16 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*ft_copy_from_stack(char *stack, char *buffer)
{
	char	*new_stack;

	new_stack = 0;
	if (!stack && buffer)
	{
		new_stack = ft_strdup(buffer);
		if (!new_stack)
			return (NULL);
		return (new_stack);
	}
	new_stack = ft_strjoin(stack, buffer);
	ft_clean(&stack, 0);
	return (new_stack);
}

static int	ft_check_nl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*get_first_line(char *stack)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stack)
		return (0);
	while (stack[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = 0;
	while (j < (i + 1))
	{
		line[j] = stack[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*get_new_line(char *stack)
{
	size_t	i;
	char	*new_stack;

	i = 0;
	if (!stack)
		return (NULL);
	while (stack[i] != '\n')
		i++;
	if (stack[i + 1] == '\0')
		return (ft_clean(&stack, 0));
	new_stack = ft_substr(stack, i + 1, ft_strlen(stack));
	if (!new_stack)
	{
		ft_clean(&stack, 0);
		return (NULL);
	}
	ft_clean(&stack, 0);
	return (new_stack);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	long		byte;
	static char	*stack = NULL;
	char		*line;

	line = 0;
	byte = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_clean(&stack, 0));
	while (byte > 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if ((byte <= 0 && !stack) || byte == -1)
			return (ft_clean(&stack, 0));
		buffer[byte] = '\0';
		stack = ft_copy_from_stack(stack, buffer);
		if (ft_check_nl(stack))
		{
			line = get_first_line(stack);
			if (!line)
				return (ft_clean(&stack, 0));
			return (stack = get_new_line(stack), line);
		}
	}
	return (ft_clean(&stack, 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:34:17 by muyucego          #+#    #+#             */
/*   Updated: 2023/12/14 03:50:49 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_new_str(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dest)
	{
		free(str);
		return (NULL);
	}
	j = 0;
	i++;
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	return (free(str), dest);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_trimlast(str, '\n');
	str = ft_new_str(str);
	return (line);
}

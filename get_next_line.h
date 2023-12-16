/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:34:26 by muyucego          #+#    #+#             */
/*   Updated: 2023/12/14 03:35:36 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*ft_trimlast(char *str, char c);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);
char	*ft_new_str(char *str);
size_t	ft_strlen(char *str);

#endif
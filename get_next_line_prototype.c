#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *get_line(int fd)
{
	int i;
	char	*str;
	int	byte;
	char c;
	i = 0;
	str = (char *)malloc(999999);
	if (!str)
		return (NULL);
	if (fd < 0)
		return (NULL);
	byte = read(fd, &c, 1);
	while (byte > 0)
	{
		str[i] = c;
		i++;
		if (c == '\n' || c == -1)
			break;
		byte = read(fd, &c, 1);
	}
	if (byte < 0 || i == 0)
	{
		free(str);
		return (NULL);
	}
	str[i] = '\0';
	return (str);
}

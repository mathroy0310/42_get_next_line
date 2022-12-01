/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:17:16 by marvin            #+#    #+#             */
/*   Updated: 2022/11/30 20:18:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && str == NULL))
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff); 
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if(!str)
		return (NULL);
	line = ft_line(str);
	return(line);
}

int main(void)
{
	int fd;
	char *tab;
	fd = open("test.txt", O_RDONLY);
	tab = get_next_line(fd);
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	close(fd);
		return(0);
}

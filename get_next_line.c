/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:17:16 by marvin            #+#    #+#             */
/*   Updated: 2022/12/02 20:09:28 by maroy            ###   ########.fr       */
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
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && str == NULL))
		{
			free(buff);
			free(str);
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
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_next_line(str);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*tab;

// 	fd = open("nl", O_RDONLY);
// 	tab = get_next_line(fd);
// 	printf("%s", tab);
// 	free(tab);
// 	tab = get_next_line(fd);
// 	printf("%s", tab);
// 	free(tab);
// 	tab = get_next_line(fd);
// 	printf("%s", tab);
// 	free(tab);
// 	tab = get_next_line(fd);
// 	printf("%s", tab);
// 	close(fd);
// 	return (0);
// }

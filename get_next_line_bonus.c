/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:17:16 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 11:12:47 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_line(char *str)
{
	int		i;
	char	*tab;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	tab = (char *)malloc(sizeof(char) * (i + 2));
	if (!tab)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tab[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tab = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!tab)
	{
		free(tab);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i] && str)
		tab[j++] = str[i++];
	tab[j] = '\0';
	free(str);
	return (tab);
}

static char	*ft_read(int fd, char *str)
{
	char	*tmp;
	int		bytes;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (0);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			free(str);
			return (0);
		}
		tmp[bytes] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_line(str[fd]);
	str[fd] = ft_next_line(str[fd]);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/

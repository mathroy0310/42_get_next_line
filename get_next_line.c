/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroy <maroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:17:16 by marvin            #+#    #+#             */
/*   Updated: 2022/12/08 11:10:53 by maroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = ft_read(fd, buff);
	if (!buff)
		return (0);
	line = ft_line(buff);
	buff = ft_next_line(buff);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*tab;

// 	fd = open("read_error.txt", O_RDONLY);
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
// 	free(tab);
// 	tab = get_next_line(fd);
// 	printf("%s", tab);
// 	free(tab);
// 	close(fd);
// 	return (0);
// }

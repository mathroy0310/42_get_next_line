/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:17:57 by marvin            #+#    #+#             */
/*   Updated: 2022/11/23 15:17:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *l_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!l_str)
	{
		l_str = (char *)malloc(1 * sizeof(char));
		l_str[0] = '\0';
	}
	if (!l_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) *((ft_strlen(l_str) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (l_str)
		while (l_str[++i])
			str[i] = l_str[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[ft_strlen(l_str) + ft_strlen(buff)] = '\0';
	free(l_str);
	return (str);
}

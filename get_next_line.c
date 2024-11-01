/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghlimi <aghlimi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:47:24 by aghlimi           #+#    #+#             */
/*   Updated: 2024/11/01 21:40:41 by aghlimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

static int	ft_str_len(const char *text)
{
	int	i;

	i = 0;
	if (text)
		while (text[i])
			i++;
	return (i);
}
static char	*ft_addchar(char *text, char c)
{
	int		i;
	char	*result;

	result = ft_calloc(ft_str_len(text) + 2, 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (text)
	{
		ft_memmove(result, text, ft_str_len(text));
		free(text);
	}
	result[ft_str_len(result)] = c;
	return (result);
}

char	*ft_tonl(char *text)
{
	int		i;
	char	*result;

	i = 0;
	result = NULL;
	while (text[i])
	{
		result = ft_addchar(result, text[i]);
		if (!result)
			return (NULL);
		if (text[i++] == 10)
			return (result);
	}
	return (result);
}

int	firstnl(char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (text[i++] == 10)
			return (i);
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	char		*xd3ndkblati;
	char		*xd3ndkblati7tanta;

	result = NULL;
	if (ft_strlen(buffer))
	{
		result = ft_tonl(buffer);
		if (!result)
			return (NULL);
		ft_memmove(buffer, buffer + firstnl(buffer), ft_strlen(buffer) + 1);
	}
	if ((result && !ft_strchr(result, 10)) || !result)
		while (read(fd, buffer, BUFFER_SIZE) > 0)
		{
			xd3ndkblati = result;
			xd3ndkblati7tanta = ft_tonl(buffer);
			if (!xd3ndkblati7tanta)
				return (free(xd3ndkblati), NULL);
			result = ft_strjoin(result, xd3ndkblati7tanta);
			if (!result)
				return (free(xd3ndkblati7tanta), free(xd3ndkblati), NULL);
			free((free(xd3ndkblati),xd3ndkblati7tanta));
			if (ft_strchr(result, 10))
				return (ft_memmove(buffer, buffer + firstnl(buffer),
						ft_strlen(buffer) + 1), result);
		}
	return (result);
}
int	main(int argc, char const *argv[])
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("fd");
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}

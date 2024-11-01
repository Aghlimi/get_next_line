/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghlimi <aghlimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:47:24 by aghlimi           #+#    #+#             */
/*   Updated: 2024/11/01 14:26:45 by aghlimi          ###   ########.fr       */
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
char	*addchar(char *text, char c)
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
		result = addchar(result, text[i]);
		if (!result)
			return (NULL);
		if (text[i++] == 10)
			return (result);
	}
	return (result);
}

char	*ft_fromnl(char *text)
{
	char	*d;

	d = ft_strchr(text, 10);
	if (d)
		d++;
	return (d);
}

char	*get_next_line(int fd)
{
	static char		*mem;
	static ssize_t	readed;
	static int		started;
	char			buffer[BUFFER_SIZE + 1];
	char			*result;

	char *d, *n;
	result = NULL;
	if (mem)
	{
		result = ft_tonl(mem);
		if (!result)
			return (NULL);
	}
	if (!(started && readed) && (!result || (result && result[ft_strlen(result)
				- 1] != 10)))
	{
		while ((readed = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			started = 1;
			d = ft_tonl(buffer);
			n = result;
			if (!d)
				return (NULL);
			result = ft_strjoin(result, d);
			free(n);
			free(d);
			if (ft_strchr(result,10))
			{
				mem = ft_fromnl(buffer);
				break ;
			}
		}
	}
	else if (mem)
		mem = ft_fromnl(mem);
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
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }
	return (0);
}

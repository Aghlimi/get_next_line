/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghlimi <aghlimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:03:32 by aghlimi           #+#    #+#             */
/*   Updated: 2024/10/31 14:33:21 by aghlimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

char	*addchar(char *text, char c)
{
	int		i;
	char	*result;

	result = ft_calloc(ft_strlen(text) + 2, 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (text)
		ft_memmove(result, text, ft_strlen(text));
	result[ft_strlen(text)] = c;
	return (result);
}

char	*ft_fromnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ((char *)(s + i + 1));
		i++;
	}
	return (NULL);
}

char	*ft_tonl(char *dst, char *text)
{
	size_t	i;

	i = 0;
	if (!text)
		return (ft_strdup(""));
	while (text[i])
	{
		dst = addchar(dst, text[i]);
		if (!dst)
			return (NULL);
		if (text[i++] == 10)
			break ;
	}
	return (dst);
}

char	*ft_read(char *text, int fd)
{
	static int	readed;
	static int	finished;
	ssize_t		r;
	char		buffer[BUFFER_SIZE + 1];

	ft_bzero(buffer, BUFFER_SIZE + 1);
	r = read(fd, buffer, BUFFER_SIZE);
	while (r)
	{
		
		text = ft_strjoin(text, buffer);
		if (ft_strchr(buffer, 10))
			return (text);
		r = read(fd, buffer, BUFFER_SIZE);
		printf("number = %zd\n",r);
	}
	return (text);
}

char	*get_next_line(int fd)
{
	char		*result;
	char		*res;
	static char	*mem;

	result = ft_tonl(result, mem);
	if (!result)
		return (NULL);
	if (result && result[ft_strlen(result) - 1] == 10)
	{
		mem = ft_fromnl(mem);
		if (mem == NULL)
		{
			free(result);
			return (NULL);
		}
		return (result);
	}
	else if (result)
	{
		res = ft_read(result, fd);
		mem = ft_fromnl(res);
		result = ft_tonl(result, res);
	}
	printf("\n mem = %s\n", mem);
	printf("\n result = %s\n", result);
	return (result);
}

int	main(int argc, char const *argv[])
{
	int		fd;
	char	*line;
	char	*text;
	char	*f;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("fd");
		return (1);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// return (0);
}

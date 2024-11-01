/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghlimi <aghlimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:47:24 by aghlimi           #+#    #+#             */
/*   Updated: 2024/10/31 20:51:34 by aghlimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1

char	*addchar(char *text, char c)
{
	int		i;
	char	*result;

	result = ft_calloc(ft_strlen(text) + 2, 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	if (text)
	{
		ft_memmove(result, text, ft_strlen(text));
		free(text);
	}
	result[ft_strlen(text)] = c;
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
		if (text[i++] == 10)
			return (result);
	}
	return (result);
}

char* 

char	*get_next_line(int fd)
{
	static char		*mem;
	static ssize_t	readed;
	char			buffer[BUFFER_SIZE + 1];
	char			*result;

	ft_bzero(buffer, BUFFER_SIZE);
	result = NULL;
	if (mem)
	{
		result = ft_tonl(mem);
		if (!result)
			return (NULL);
	}
	if (result && result[ft_strlen(result) - 1] != 10)
	{
		while ((readed = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
		}
	}
	else
	{
		mem = ft_fromnl(mem);
	}
	
}

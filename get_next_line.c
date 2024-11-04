/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghlimi <aghlimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:47:24 by aghlimi           #+#    #+#             */
/*   Updated: 2024/11/04 23:44:40 by aghlimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_fromnl(char *buffer)
{
	int	nl;
	int	i;

	i = 0;
	nl = firstnl(buffer);
	if (nl == -1)
		buffer[0] = 0;
	else
	{
		while (buffer[nl])
			buffer[i++] = buffer[nl++];
		buffer[i] = 0;
	}
}

char	*ft_read(int fd, char *buffer, char *result)
{
	char	*r;
	char	*tonl;
	ssize_t	n;

	n = read(fd, buffer, BUFFER_SIZE);
	printf("n=%d\n",n);
	while (n > 0)
	{
		
		buffer[n] = 0;
		r = result;
		tonl = ft_tonl(buffer);
		if (!tonl)
			return (free(r), NULL);
		result = ft_strjoin(result, tonl);
		if (!result)
			return (free(tonl), free(r), NULL);
		free((free(r), tonl));
		if (result[ft_str_len(result) - 1] == '\n')
			break ;
		n = read(fd, buffer, BUFFER_SIZE);
	}
	ft_fromnl(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
printf("%ld\n",sizeof(buffer));
	result = NULL;
	if (ft_str_len(buffer))
	{
		result = ft_tonl(buffer);
		if (!result)
			return (NULL);
		ft_fromnl(buffer);
	}
	if ((result && result[ft_str_len(result) - 1] != '\n') || !result)
		result = ft_read(fd, buffer, result);
	return (result);
}

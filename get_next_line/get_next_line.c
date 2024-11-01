/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghlimi <aghlimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:47:24 by aghlimi           #+#    #+#             */
/*   Updated: 2024/11/01 22:15:54 by aghlimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer, char *result)
{
	char	*xd3ndkblati;
	char	*xd3ndkblati7tanta;

	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		xd3ndkblati = result;
		xd3ndkblati7tanta = ft_tonl(buffer);
		if (!xd3ndkblati7tanta)
			return (free(xd3ndkblati), NULL);
		result = ft_strjoin(result, xd3ndkblati7tanta);
		if (!result)
			return (free(xd3ndkblati7tanta), free(xd3ndkblati), NULL);
		free((free(xd3ndkblati), xd3ndkblati7tanta));
		if (ft_strchr(result, 10))
			return (ft_memmove(buffer, buffer + firstnl(buffer),
					ft_strlen(buffer) + 1), result);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;

	result = NULL;
	if (ft_strlen(buffer))
	{
		result = ft_tonl(buffer);
		if (!result)
			return (NULL);
		ft_memmove(buffer, buffer + firstnl(buffer), ft_strlen(buffer) + 1);
	}
	if ((result && !ft_strchr(result, 10)) || !result)
		result = ft_read(fd, buffer, result);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghlimi <aghlimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:56:35 by aghlimi           #+#    #+#             */
/*   Updated: 2024/11/01 22:13:38 by aghlimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_str_len(const char *text)
{
	int	i;

	i = 0;
	if (text)
		while (text[i])
			i++;
	return (i);
}

char	*ft_addchar(char *text, char c)
{
	char	*result;

	result = ft_calloc(ft_str_len(text) + 2, 1);
	if (result == NULL)
		return (NULL);
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

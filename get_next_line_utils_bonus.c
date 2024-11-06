/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghlimi <aghlimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:56:35 by aghlimi           #+#    #+#             */
/*   Updated: 2024/11/06 16:04:00 by aghlimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_str_len(const char *text)
{
	int	i;

	i = 0;
	if (text)
		while (text[i])
			i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(ft_str_len(s1) + ft_str_len(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	if (s2)
		while (s2[j])
			str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

char	*ft_tonl(char *text)
{
	int		i;
	int		nl;
	char	*result;

	nl = firstnl(text);
	i = 0;
	if (nl == -1)
		nl = ft_str_len(text);
	result = malloc(nl + 1);
	if (!result)
		return (NULL);
	result[nl] = 0;
	while (i < nl)
	{
		result[i] = text[i];
		i++;
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

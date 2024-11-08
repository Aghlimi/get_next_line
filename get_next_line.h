/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghlimi <aghlimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:54:05 by aghlimi           #+#    #+#             */
/*   Updated: 2024/11/06 18:00:36 by aghlimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		ft_str_len(const char *text);
char	*ft_addchar(char *text, char c);
char	*ft_tonl(char *text);
int		firstnl(char *text);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

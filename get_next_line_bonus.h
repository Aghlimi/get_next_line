/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghlimi <aghlimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:41:52 by aghlimi           #+#    #+#             */
/*   Updated: 2024/11/06 18:06:38 by aghlimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define MAX_FD 10240
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_str_len(const char *text);
char	*ft_addchar(char *text, char c);
char	*ft_tonl(char *text);
int		firstnl(char *text);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

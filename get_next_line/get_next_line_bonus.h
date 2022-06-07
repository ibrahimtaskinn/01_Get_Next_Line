/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaskin <taskinnibrahim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:24:14 by itaskin           #+#    #+#             */
/*   Updated: 2022/03/03 14:24:16 by itaskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
size_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(char *s, int c);

#endif

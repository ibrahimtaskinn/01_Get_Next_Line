/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaskin <taskinnibrahim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:13:51 by itaskin           #+#    #+#             */
/*   Updated: 2022/03/03 14:27:17 by itaskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*ft_one_line(char *str)
{
	char	*oneline;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	oneline = (char *)malloc(sizeof(char) * (i + 2));
	if (!oneline)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		oneline[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		oneline[i] = str[i];
		i++;
	}
	oneline[i] = '\0';
	return (oneline);
}

static char	*ft_remain(char *str)
{
	char	*remain;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	remain = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!remain)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		remain[j++] = str[i++];
	remain[j] = '\0';
	free(str);
	return (remain);
}

static char	*ft_read_file(char *str, int fd)
{
	char	*buff;
	int		cont;

	cont = 1;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr(str, '\n') && cont != 0)
	{
		cont = read(fd, buff, BUFFER_SIZE);
		if (cont == -1)
		{
			free (buff);
			return (0);
		}
		buff[cont] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*oneline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read_file(str[fd], fd);
	if (!str[fd])
		return (NULL);
	oneline = ft_one_line(str[fd]);
	str[fd] = ft_remain(str[fd]);
	return (oneline);
}

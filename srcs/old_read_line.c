/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 22:47:22 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/11 19:11:31 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_error(char **line)
{
	ft_putendl_fd("read error: abort prog", 2);
	ft_memdel((void*)line);
	exit (-1);
}

int		read_line(int fd, char **line)
{
	char	*buf;
	char	*tmp;
	int		ret;

	if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE) + 1)))
		exit(1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret < 0)
		read_error(&buf);
	while (0 < ret && buf[ret - 1] != 10)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin((*line), buf);
		ft_strdel(line);
		(*line) = tmp;
		ret = read(fd, buf, BUFF_SIZE);
	}
	buf[ret] = '\0';
	tmp = ft_strjoin((*line), buf);
	ft_strdel(line);
	(*line) = tmp;
	ft_strdel(&buf);
	return (ret);
}

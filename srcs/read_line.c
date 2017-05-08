/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 22:47:22 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/08 23:43:40 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_error(char **line)
{
	ft_putendl_fd("read error: abort prog", 2);
	ft_memdel((void*)line);
	exit (-1);
}

int		read_line(const int fd, char **line)
{
	char	*tmp;
	int		ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!((*line) = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if ((ret = read(fd, *line, BUFF_SIZE)) < 0)
		read_error(line);
	while ((ret > 0) && ((*line)[ret - 1] != 10))
	{
		(*line)[ret - 1] = '\0';
		tmp = ft_strjoin(tmp, *line);
		ft_memdel((void*)line);
		ret = read(fd, (*line), BUFF_SIZE);
	}
	(*line)[ret - 1] = '\0';
	return (ret);
}

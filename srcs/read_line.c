/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 22:47:22 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/11 16:22:58 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_error(char **line)
{
	ft_putendl_fd("read error: abort prog", 2);
	ft_memdel((void*)line);
	exit (-1);
}

#include <stdio.h>
#include <unistd.h>

int		read_line(const int fd, char **line)
{
	char	*save;
	int		ret;

	ret = 0;
	save = NULL;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!((*line) = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if ((ret = read(fd, *line, BUFF_SIZE)) < 0)
		read_error(line);
	(*line)[ret] = '\0';
	printf("line = %p\n", *line);
	while ((ret > 0) && ((*line)[ret - 1] != 10))
	{
		printf("line = %p\n", *line);
		printf("save = %p\n", save);
		save = ft_strjoin_fb(save, *line);
		ret = read(fd, (*line), BUFF_SIZE);
		(*line)[ret] = '\0';
	}
	(*line) = ft_strjoin_fb(save, (*line));
	save != NULL ? ft_strdel(&save) : NULL;
	return (ret);
}

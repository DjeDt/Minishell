/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 22:47:22 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/09 17:40:30 by ddinaut          ###   ########.fr       */
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

	tmp = NULL;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!((*line) = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if ((ret = read(fd, *line, BUFF_SIZE)) < 0)
		read_error(line);
	while ((ret > 0) && ((*line)[ret - 1] != 10))
	{
		if (tmp != NULL)
			ft_strdel(&tmp);
		ft_putendl("test1");
		(*line)[ret - 1] = '\0';
		ft_putendl("test2");
		tmp = ft_strjoin_fr(tmp, *line);
		ft_putendl("test3");
//		ft_memdel((void*)line);
		ret = read(fd, (*line), BUFF_SIZE);
		if (ret < 0)
			break ;
		ft_putendl("test4");
	}
	(*line)[ret - 1] = '\0';
	if (tmp != NULL)
		ft_memdel((void*)&tmp);
	return (ret);
}

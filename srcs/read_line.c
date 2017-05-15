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
/*
static void	read_error(char **line)
{
	ft_putendl_fd("read error: abort prog", 2);
	ft_memdel((void*)line);
	exit (-1);
}
*/
/*
static void add_char(char c, char **str)
{
	int count;
	char *new;

	count = -1;
	new = (char*)malloc(sizeof(char) * ft_strlen(*str) + 2);
	while (*str[++count] != '\0')
		new[count] = *str[count];
	new[++count] = c;
	new[++count] = '\0';
	ft_strdel(str);
	*str = new;
}
*/
int		read_line(int fd, char **line)
{
	char	*tmp;
	char	*buf;
	int		ret;
//	int		pos;

//	pos = 0;
	mode_raw();
	if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE) + 1)))
		exit(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0 && buf[ret - 1] != 10)
	{
		buf[ret] = '\0';

		*buf == 65 ? ft_putendl("up") : 0;
		*buf == 66 ? ft_putendl("down") : 0;
		*buf == 67 ? ft_putendl("right") : 0;
		*buf == 68 ? ft_putendl("left") : 0;
		*buf == 126 ? ft_putendl("suppr") : 0;

		tmp = ft_strjoin((*line), buf);
		ft_strdel(line);
		(*line) = tmp;
	}
	ft_strdel(&buf);
	return (ret);
}

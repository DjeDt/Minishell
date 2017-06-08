/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_hist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:01:50 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/07 20:04:31 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

static void	realoc_line(char **buf)
{
	static int i;
	char *new;

	i = 2;
	if (!(new = (char*)malloc(sizeof(char) * 1024 * i)))
		return ;
	ft_bzero(new, 1024 * i);
	ft_strcpy(new, *buf);
	ft_strdel(buf);
	*buf = new;
}

int		read_hist(const int fd, char **buf)
{
	int		ret;
	char	c;
	int		count;

	if (!(*buf = (char*)malloc(sizeof(char) * 1024)))
		return (-1);
	ft_bzero(*buf, 1024);
	count = 0;
	while (!(ft_strchr(*buf, '\n')))
	{
		if (count == 1024)
			realoc_line(buf);
		ret = read(fd, &c, 1);
		if (ret == 0)
			return (0);
		if (ret == -1)
			return (-1);
		ft_putendl("test");
		*buf[count++] = c;
		ft_putendl("test1");
	}
	return (0);
}

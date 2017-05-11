/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:15:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/11 19:15:57 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>

int		core_arrow(const char *input)
{
	struct termios	test;
	int count;

	count = 0;
	if (ioctl(0, TIOCGWINSZ, &test) < 0)
		ft_putendl_fd("error", 2);
	test.c_lflag &= ~(ICANON | ECHO);
	if ((ioctl(0, TIOCGWINSZ, &test)) < 0)
		ft_putendl_fd("error", 2);
	while (input[count] != '\0')
	{
		if (input[count])
			ft_putendl("test");
		count++;
	}
	return (0);
}

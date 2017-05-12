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
	struct winsize test;

	ioctl(0, TIOCGWINSZ, &test);

	(void)input;
	ft_putstr("colonne = ");
	ft_putnbr(test.ws_col);
	ft_putstr("\ncligne = ");
	ft_putnbr(test.ws_row);
	return (0);
}

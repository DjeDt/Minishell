/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:59:52 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/17 18:04:06 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(char **input, t_env **list)
{
	int		count;

	count = 0;
	(void)list;
	while (input[++count] != NULL)
	{
		ft_putstrlen(input[count]);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:59:52 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/18 12:24:18 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(const char **input)
{
	int count;

	count = 0;
	if (input == NULL)
		return (-1);
	while (input[++count] != NULL)
	{
		ft_putstr(input[count]);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}

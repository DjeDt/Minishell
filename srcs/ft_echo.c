/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:59:52 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/30 17:12:26 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *input, char **environ)
{
	char **tmp = ft_split_whitespaces(input);
	int count;

	count = -1;
	while (tmp[++count])
	{
		ft_putstrlen(tmp[count]);
		write(1, "\n", 1);
	}

//	ft_putendl(ft_strchr(input, 'o') + 2);
	exit (0);
}

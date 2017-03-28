/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:59:52 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/28 17:05:09 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char *input)
{
	int		count;
	char	**tmp;

	count = 0;
	tmp = ft_split_whitespaces(input);
	while (tmp[++count])
		ft_putstrlen(tmp[count]);
	ft_putchar('\n');
	count = -1;
	while (tmp[++count])
		ft_memdel((void*)tmp[count]);
	ft_memdel((void**)tmp);
	exit (0);
}

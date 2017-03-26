/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/24 14:49:44 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char **environ;

static int	one_of(char c)
{
	if (ft_strchr(flg_env, c))
		return (c);
	else
		arg_error(c);
}

static int	arg_check(char **input)
{
	int i;
	int j;
	int arg;

	i = 0;
	arg = 0;
	if (input[1][0] == '-' && imput[1][1] != '\0')
	{
		while (input[++i])
		{
			while (input[i][j]
		}
	}
}

void		ft_env(char **input)
{
	int i;

	i = arg_check(input);
	if (i == 0)
		ft_tabprint(environ);
	else
	{
		if (ft_strncmp(input[1], "-i", 2) == 0)
			ft_putendl("on lance les options");
	}
}

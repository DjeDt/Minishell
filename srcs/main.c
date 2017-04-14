/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/07 16:06:11 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_input(char **input, char ***env, char **cmd)
{
	int		count;
	test	tt[6] ={
		{"env", &ft_env},
		{"setenv", &ft_setenv},
		{"unsetenv", &ft_unsetenv},
		{"echo", &ft_echo},
		{"cd", NULL},
		{"exit", NULL}
	};

	count = -1;
	if (input[0] == NULL)
		return ;
	while (++count < 6)
	{
		if (ft_strcmp(tt[count].ft, input[0]) == 0)
		{
			(*(tt[count].func))(input, env);
			return ;
		}
	}
	ft_getprog(cmd);
}

int		main(void)
{
	char		*cmd;
	char		**env;
	char		**input;

	env = ft_cpyenv();
	while (1)
	{
		ft_putstrlen("user\n--> ");
		get_next_line(0, &cmd);
		input = ft_split_whitespaces(cmd);
		ft_check_input(input, &env, input);
		ft_memdel((void*)&cmd);
	}
	ft_arrayfree(&env);
	ft_arrayfree(&input);
	return (0);
}

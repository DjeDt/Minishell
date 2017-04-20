/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/20 16:48:04 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_builtins(char **input, char ***ar_env)
{
	int			count;
	s_builtin	builtin[6] = {
		{"env", &ft_env},
		{"setenv", &ft_setenv},
		{"unsetenv", &ft_unsetenv},
		{"echo", &ft_echo},
		{"cd", &ft_cd},
		{"exit", &ft_exit}
	};

	count = -1;
	if (input[0] == NULL)
		return (-1);
	while (++count < 6)
	{
		if (ft_strcmp(builtin[count].ft, input[0]) == 0)
		{
			(*(builtin[count].func))(input, ar_env);
			return (1);
		}
	}
	return (0);
}

int			main(void)
{
	char		*cmd;
	char		**input;
	char		**env;

	cmd = NULL;
	input = NULL;
	env = get_environ();
	while (1)
	{
		ft_putstrlen("$> ");
		get_next_line(0, &cmd);
		input = ft_split_whitespaces(cmd);
		check_builtins(input, &env) != 1 ? ft_launch_prog(input, env) : 0;
		ft_memdel((void*)&cmd);
	}
	ft_array_free(&input);
	ft_array_free(&env);
	return (0);
}

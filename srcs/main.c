/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/30 17:12:38 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_check_input(char *input, char **environ)
{
	int		count;
	char	**tmp;
	test	tt[6] ={
		{"env", &ft_env},
		{"setenv", NULL},
		{"unsetenv", NULL},
		{"echo", &ft_echo},
		{"cd", NULL},
		{"exit", NULL}
	};

	count = -1;
	tmp = ft_split_whitespaces(input);
	while (++count < 6)
	{
		if (ft_strcmp(tt[count].ft, tmp[0]) == 0)
			(*(tt[count].func))(input, environ);
	}
	return (NULL);
}

int			main(void)
{
	char		*cmd;
	pid_t		proc;
	char		**env;

	env = ft_cpyenv();
	while (1)
	{
		proc = fork();
		if (proc > 0)
			wait(0);
		if (proc == 0)
		{
			ft_putstrlen("user\n--> ");
			get_next_line(0, &cmd);
			if (ft_check_input(cmd, env) == NULL)
				ft_getprog(ft_split_whitespaces(cmd));
			free(cmd);
			cmd = NULL;
		}
	}
	return (0);
}

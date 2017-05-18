/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/18 12:25:23 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_builtins(const char *input)
{
	int			count;
	char		**tmp;
	s_builtin	builtin[6] = {
		{"env", &ft_env},
		{"setenv", &ft_setenv},
		{"unsetenv", &ft_unsetenv},
		{"echo", &ft_echo},
		{"cd", &ft_cd},
		{"exit", &ft_exit}
	};

	count = -1;
	tmp = ft_split_whitespaces((char*)input);
	while ((tmp[0]) && (++count < 6))
	{
		if (ft_strcmp(builtin[count].ft, tmp[0]) == 0)
		{
			(*(builtin[count].func))((const char **)tmp);
			ft_arrfree(&tmp);
			return (0);
		}
	}
	tmp[0] != NULL ? ft_launch_prog((const char **)tmp) : 0;
	tmp != NULL ? ft_arrfree(&tmp) : NULL;
	return (0);
}

static void	core(void)
{
	int		count;
	char	*line;
	char	**cmd;

	line = NULL;
	cmd = NULL;
	print_launch();
	while (1)
	{
		count = 0;
		print_prompt();
		read_line(0, &line);
		cmd = ft_strsplit(line, ';');
		ft_memdel((void*)&line);
		while (cmd[count] != NULL)
			check_builtins(cmd[count++]);
		ft_arrfree(&cmd);
	}
}

int			main(void)
{
	g_env = NULL;
	get_environ();
	mode_raw();
	core();
	return (0);
}

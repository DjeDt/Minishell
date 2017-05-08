/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/08 23:26:43 by ddinaut          ###   ########.fr       */
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
	if ((tmp = ft_split_whitespaces((char*)input)) == NULL)
		return (-1);
	while ((tmp[0]) && (++count < 6))
	{
		if (ft_strcmp(builtin[count].ft, tmp[0]) == 0)
		{
			(*(builtin[count].func))((const char **)tmp);
			ft_array_free(&tmp);
			return (0);
		}
	}
	if (tmp[0] != NULL)
		ft_launch_prog(tmp);
	ft_array_free(&tmp);
	return (0);
}

static void	core(void)
{
	int		count;
	char	*line;
	char	**cmd;

	line = NULL;
	cmd = NULL;
	while (1)
	{
		count = 0;
		ft_putstrlen("$> ");
		read_line(0, &line);
		cmd = ft_strsplit(line, ';');
		ft_memdel((void*)&line);
		while (cmd[count] != NULL)
			check_builtins(cmd[count++]);
		ft_array_free(&cmd);
	}
}

int			main(void)
{
	get_environ();
	core();
	ft_array_free(&g_env);
	return (0);
}

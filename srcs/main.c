/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/25 17:02:55 by ddinaut          ###   ########.fr       */
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
	if (tmp == NULL)
		return (-1);
	while (++count < 6)
	{
		if (ft_strcmp(builtin[count].ft, tmp[0]) == 0)
		{
			(*(builtin[count].func))((const char **)tmp);
			return (0);
		}
	}
	ft_launch_prog(tmp);
	ft_array_free(&tmp);
	return (0);
}

static void	core(void)
{
	int		count;
	char	*line;
	char	**cmd;

	while (1)
	{
		count = 0;
		ft_putstrlen("$> ");
		get_next_line(0, &line);
		cmd = ft_strsplit(line, ';');
		while (cmd[count] != NULL)
			check_builtins(cmd[count++]);
		ft_memdel((void*)&line);
		ft_array_free(&cmd);
	}
}

int			main(void)
{
	g_env = get_environ();
	core();
	ft_array_free(&g_env);
	return (0);
}

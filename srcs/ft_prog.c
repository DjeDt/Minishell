/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:46:18 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/20 18:17:56 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_spawn(char **av, char **diff_p)
{
	pid_t	child;
	int		count;
	char	*tmp;

	child = fork();
	if (child != 0)
		wait(&child);
	else
	{
		count = -1;
		while (diff_p[++count] != NULL)
		{
			tmp = ft_strjoin_fl(ft_strjoin(diff_p[count], "/"), av[0]);
			if (access(av[0], F_OK) == 0)
				execve(av[0], av, g_env);
			else if (access(tmp, F_OK) == 0)
				execve(tmp, av, g_env);
			ft_memdel((void*)&tmp);
		}
	}
}

int				ft_launch_prog(char **av)
{
	char	**diff_p;

	diff_p = split_path(get_var_value(g_env, "PATH"));
	ft_spawn(av, diff_p);
	ft_array_free(&diff_p);
	return (0);
}

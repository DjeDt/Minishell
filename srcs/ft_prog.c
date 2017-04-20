/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:46:18 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/18 15:15:17 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_spawn(char **av, char **env)
{
	int		count;
	char	*tmp;
	char	**diff_p;

	count = -1;
	diff_p = split_path(get_var_value(env, "PATH"));
	while (diff_p[++count] != NULL)
	{
		tmp = ft_strjoin(diff_p[count], "/");
		tmp = ft_strjoin_fl(tmp, av[0]);
		execve(tmp, av, env);
		ft_memdel((void*)&tmp);
	}
	ft_array_free(&diff_p);
}

int				ft_launch_prog(char **av, char **env)
{
	pid_t child;

	child = fork();
	if (child != 0)
		wait(&child);
	else
	{
		ft_spawn(av, env);
		ft_putstrlen_fd("Commande introuvable: ", 2);
		ft_putendl_fd(av[0], 2);
		ft_exit(av, &env);
	}
	return (0);
}

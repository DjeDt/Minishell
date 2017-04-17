/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:46:18 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/07 12:42:41 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_spawn(char **av)
{
	int		count;
	char	*tmp;
	char	**env_path;

	count = -1;
	env_path = ft_getpath(ft_getenv("PATH"));
	while ((env_path != NULL) && (env_path[++count]))
	{
		tmp = ft_strjoin(env_path[count], "/");
		execve(ft_strjoin(tmp, av[0]), av, NULL);
		ft_memdel((void*)&tmp);
	}
	ft_arrayfree(&env_path);
}

int		ft_getprog(char **av)
{
	pid_t child;

	child = fork();
	if (child != 0)
		wait(&child);
	else
	{
		ft_spawn(av);
		ft_putstrlen("commande introuvable: ");
		ft_putendl(av[0]);
	}
	return(0);
}

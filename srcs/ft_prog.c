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

int		ft_spawn(char **av)
{
	int		count;
	char	*tmp;
	char	**path;

	count = -1;
	path = ft_getpath(ft_getenv("PATH"));
	while ((path != NULL) && (path[++count]))
	{
		tmp = ft_strjoin(path[count], "/");
		execve(ft_strjoin(tmp, av[0]), av, NULL);
		ft_memdel((void*)&tmp);
	}
	ft_arrayfree(&path);
	return (0);
}

void	ft_getprog(char **av)
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
}

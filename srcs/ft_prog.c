/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:46:18 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/24 14:34:39 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_getprog(char **av)
{
	int		count;
	char	*tmp;
	char	**path;

	count = -1;
	tmp = NULL;
	path = ft_getpath(ft_getenv("PATH"));
	while (path != NULL && path[++count])
	{
		tmp = ft_strjoin(path[count], "/");
		execve(ft_strjoin(tmp, av[0]), av, NULL);
		free(tmp);
		tmp = NULL;
	}
	ft_putstrlen("commande introuvable: ");
	ft_putendl(av[0]);
	ft_tabfree(path);
	ft_tabfree(av);
	return (NULL);
}

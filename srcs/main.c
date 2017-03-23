/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/23 19:44:27 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(int argc, char **argv)
{
	char		**tmp;
	char		**env;
	pid_t		proc;

	(void)argc;
	tmp = NULL;
	proc = fork();
	if (father > 0)
	{

	}
	while (1)
	{
		env = ft_get_full_env();
		ft_putstrlen("$user\n--> ");
		get_next_line(1, argv);
		if (!ft_strchr(*argv, '/'))
		{
			tmp = ft_split_whitespaces(*argv);
			ft_getprog(tmp, tmp[0]);
			ft_tabfree(tmp);
		}
	}
	ft_tabfree(env);
	return (0);
}

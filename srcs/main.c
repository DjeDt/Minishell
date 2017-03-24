/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/24 11:08:18 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(void)
{
	char		**tmp;
	char		**env;
	char		*cmd;
	pid_t		proc;

	while (1)
	{
		proc = fork();
		if (proc > 0)
			wait(0);
		if (proc == 0)
		{
			env = ft_get_full_env();
			ft_putstrlen("$user\n--> ");
			get_next_line(0, &cmd);
			if (!ft_strchr(cmd, '/'))
			{
				tmp = ft_split_whitespaces(cmd);
				ft_getprog(tmp, tmp[0]);
				ft_tabfree(tmp);
			}
			free(cmd);
			ft_tabfree(env);
		}
	}
	return (0);
}

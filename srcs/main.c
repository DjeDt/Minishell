/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/27 20:52:06 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_check_input(char *cmd)
{
	char	**tmp;

	tmp = ft_split_whitespaces(cmd);
	if (ft_strncmp(tmp[0], "env ", 3) == 0)
		ft_env(tmp);
	free(tmp);
	tmp = NULL;
	return (NULL);
}

int			main(void)
{
	char		*cmd;
	pid_t		proc;

	while (1)
	{
		proc = fork();
		if (proc > 0)
			wait(0);
		if (proc == 0)
		{
			ft_putstrlen("$user\n--> ");
			get_next_line(0, &cmd);
			if (ft_check_input(cmd) == NULL)
				ft_getprog(ft_split_whitespaces(cmd));
			ft_memdel((void*)&cmd);
		}
	}
	return (0);
}

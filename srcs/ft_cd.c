/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:46:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/25 17:10:15 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_input(const char **input)
{
	if (ft_array_len(input) < 2)
	{
		ft_putendl_fd(CD_USAGE, 2);
		return (-1);
	}
	if (ft_strcmp(input[1], "~") == 0 || ft_strcmp(input[1], "-") == 0)
		return (0);
	if (access(input[1], F_OK) == -1)
	{
		ft_putstrlen_fd("cd: cannot acccess to ", 2);
		ft_putendl_fd(input[1], 2);
		return (-1);
	}
	return (0);
}

int			ft_cd(const char **input)
{
	if (check_input(input) != 0)
		return (-1);
	if (ft_strncmp(input[1], "~", 1) == 0)
		chdir(get_var_value(g_env, "HOME"));
	else if (ft_strncmp(input[1],"-", 1) == 0)
		chdir(get_var_value(g_env, "OLDPWD"));
	else
		chdir(input[1]);
	return (0);
}

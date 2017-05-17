/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:46:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/04 14:33:26 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_input(const char **input)
{
	if (ft_arrlen(input) > 2)
	{
		ft_putendl_fd(CD_USAGE, 2);
		return (-1);
	}
	return (0);
}

static void			new_oldpwd(void)
{
	char	**tmp;
	char	*value_add;

	value_add = ft_strjoin("PWD=", get_var_value("PWD"));
	if (!(tmp = (char**)malloc(sizeof(char*) * 3)))
		ft_malloc_error("builtin_cd->new_oldpwd: malloc_error", -1);
	tmp[0] = ft_strdup("setenv");
	tmp[1] = value_add;
	tmp[2] = NULL;
	ft_setenv((const char **)tmp);
	ft_arrfree(&tmp);
}

static int			move_dir(const char *path)
{
	if (access(path, F_OK) == 0)
	{
		new_oldpwd();
	    chdir(path);
	}
	else
	{
		ft_putstr_fd("cd: cannot acccess to : ", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
		return (-1);
	}
	return (0);
}

int			ft_cd(const char **input)
{
	if (check_input(input) != 0)
		return (-1);
	if (ft_arrlen(input) == 1)
	  move_dir(get_var_value("HOME"));
	else if (ft_strcmp(input[1], "~") == 0)
		move_dir(get_var_value("HOME"));
	else if (ft_strcmp(input[1], "-") == 0)
	{
		move_dir(get_var_value("OLDPWD"));
		ft_putendl(get_var_value("OLDPWD"));
	}
	else
		move_dir(input[1]);
	return (0);
}

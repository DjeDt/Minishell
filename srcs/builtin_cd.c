/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:46:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/18 12:24:14 by ddinaut          ###   ########.fr       */
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

static int	dir_error(const char *error, const char *file)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd(file, 2);
	ft_putchar('\n');
	return (-1);
}

static void	new_oldpwd(void)
{
	char	**tmp;
	char	*value_add;

	value_add = ft_strjoin("OLDPWD=", get_var_value("PWD"));
	if (!(tmp = (char**)malloc(sizeof(char*) * 3)))
		malloc_error("builtin_cd->new_oldpwd: malloc_error", -1);
	tmp[0] = ft_strdup("setenv");
	tmp[1] = value_add;
	tmp[2] = NULL;
	ft_setenv((const char **)tmp);
	ft_arrfree(&tmp);
}

static int	move_dir(const char *path)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, R_OK) == 0)
		{
			new_oldpwd();
			chdir(path);
		}
		else
			return (dir_error("cd: permission denied: ", path));
	}
	else
		return (dir_error("cd: no such file or directory: ", path));
	return (0);
}

int			ft_cd(const char **input)
{
	int ret;

	ret = 0;
	if (check_input(input) != 0)
		return (-1);
	if (ft_arrlen(input) == 1)
		ret = move_dir(get_var_value("HOME"));
	else if (ft_strcmp(input[1], "~") == 0)
		ret = move_dir(get_var_value("HOME"));
	else if (ft_strcmp(input[1], "-") == 0)
	{
		ret = move_dir(get_var_value("OLDPWD"));
		ft_putendl(get_var_value("OLDPWD"));
	}
	else
		ret = move_dir(input[1]);
	return (ret);
}

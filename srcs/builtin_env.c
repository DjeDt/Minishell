/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/11 19:27:56 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	arg_check(const char **input)
{
	int				count;
	int				count2;
	unsigned int	flags;
	char			*mask;

	count = 0;
	flags = 0;
	mask = ft_strdup("i");
	while (input[++count] && input[count][0] == '-')
	{
		count2 = 1;
		while (input[count][count2] != '\0' && input[count][0] == '-')
		{
			if (ft_strchr(mask, input[count][count2]) != NULL)
				flags |= (1 << (ft_strchr(mask, input[count][count2]) - mask));
			else
			{
				ft_memdel((void*)&mask);
				return (arg_error("env", ENV_USAGE, input[count][count2]));
			}
			count2++;
		}
	}
	ft_memdel((void*)&mask);
	return (flags);
}

static	int	prog_check(const char *path, char **tmp_arg, char **tmp_env)
{
	int		ret;
	pid_t	child;

	ret = 0;
	if (access(path, F_OK) == 0)
	{
		child = fork();
		if (child == 0)
			ret = execve(path, tmp_arg, tmp_env);
		wait(&child);
	}
	return (ret);
}

static int	prog_env(const char *prog, char **tmp_arg, char **tmp_env, char **path)
{
	int		ret;
	int		count;
	char	*tmp;

	ret = 0;
	count = 0;
	while (path[count] != NULL)
	{
		tmp = ft_strjoin(path[count], "/");
		tmp = ft_strjoin_fl(tmp, prog);
		ft_putendl(tmp);
		ret = prog_check(tmp, tmp_arg, tmp_env);
		ft_strdel(&tmp);
		count++;
	}
	return (ret);
}

static int	env_option_i(const char **input, char **path)
{
	int		count;
	int		count2;
	char	**tmp_env;
	char	**tmp_arg;

	count = 0;
	while (input[count] != NULL && (ft_strchr(input[count], '=') != NULL))
		count++;
	tmp_env = ft_arrldup(input, count);
	count2 = count;
	while (input[count2] != NULL && input[count2][0] && input[count2][0] == '-')
		count2++;
	tmp_arg = ft_arrldup(input + count + 1, count2);
	prog_env(input[count], tmp_arg, tmp_env, path);
	ft_arrfree(&tmp_env);
	ft_arrfree(&tmp_arg);
	return (0);
}

int			ft_env(const char **input)
{
	int		flags;
	char	**path;

	path = NULL;
	flags = arg_check(input);
	if (flags == -1)
		return (-1);
	else if (flags & FLAG_1)
	{
		path = ft_strsplit(get_var_value("PATH"), ':');
		env_option_i(input + 2, path);
		path != NULL ? ft_arrfree(&path) : NULL;
	}
	else if (ft_arrlen(input) == 1)
		ft_arrprint((const char **)g_env);
	return (0);
}

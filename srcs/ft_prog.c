/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:46:18 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/05 17:25:20 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	not_found(char *name)
{
	ft_putstrlen_fd(name, 2);
	ft_putendl_fd(": not found", 2);
}

static int		spawn_path(const char *path, char **av)
{
	int		ret;
	pid_t	child;

	if (access (path, F_OK) == 0)
	{
		child = fork();
		if (child == 0)
			ret = execve(path, av, g_env);
		wait(&child);
	}
	else
		return (-1);
	return (ret);
}

int				ft_launch_prog(char **av)
{
	int		ret;
	int		count;
	char	*path;
	char	**diff_p;

	ret = -1;
	fprintf(file, "\nFonction launch prog :\n");
	if (ft_strchr(av[0], '/') != NULL)
		ret = spawn_path(av[0], av);
	else
	{
		count = 0;
		diff_p = ft_strsplit(get_var_value("PATH"), ':');
		fprintf(file, "- char **diff_p = %p\n", diff_p);
		while ((diff_p != NULL) && (diff_p[count++] != NULL))
		{
//			path = ft_strjoin_fl(ft_strjoin(diff_p[count], "/"), av[0]);
			path = ft_strjoin(diff_p[count], "/");
			path = ft_strjoin_fl(path, av[0]);
			ret = spawn_path(path, av);
			ft_memdel((void*)&path);
			if (ret == 0)
				break ;
		}
		diff_p != NULL ? ft_array_free(&diff_p) : NULL;
	}
	ret < 0 ? not_found(av[0]) : 0;
	return (ret);
}

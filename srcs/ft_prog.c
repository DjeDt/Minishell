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

static int		spawn_bin(char **av)
{
	int		ret;
	pid_t	child;

	ret = 0;
	child = fork();
	if (child != 0)
		wait(&child);
	else
		ret = execve(av[0], av, g_env);
	return (ret);
}

static int		spawn_path(char **av, char **diff_p)
{
	pid_t	child;
	int		ret;
	int		count;
	char	*tmp;

	fprintf(file, "\nFonction spawn path :\n");
	ret = 0;
	tmp = NULL;
	child = fork();
	if (child != 0)
		wait(&child);
	else
	{
		count = -1;
		while (diff_p[++count] != NULL)
		{
			tmp = ft_strjoin_fl(ft_strjoin(diff_p[count], "/"), av[0]);
			fprintf(file, "- char *tmp = %p\n", tmp);
			ret = execve(tmp, av, g_env);
			ft_memdel((void*)&tmp);
		}
	}
	tmp != NULL ? ft_memdel((void*)&tmp) : NULL;
	return (ret);
}

int				ft_launch_prog(char **av)
{
	int		ret;
	char	**diff_p;

	fprintf(file, "\nFonction launch prog :\n");
	ret = 0;
	if (!av[0])
		return (-1);
	if (ft_strchr(av[0], '/') != NULL)
		ret = spawn_bin(av);
	else
	{
		/* LEAKS SUR DIFF_P */
		diff_p = ft_strsplit(get_var_value("PATH"), ':');
		fprintf(file, "- char **diff_p = %p\n", diff_p);
		ret = spawn_path(av, diff_p);
		ft_array_free(&diff_p);
	}
	if (ret != 0)
	{
		not_found(av[0]);
		exit (-1);
	}
	return (0);
}











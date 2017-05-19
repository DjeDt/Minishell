/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:21:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/18 12:24:41 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_input(const char **input)
{
	char	**tmp;

	tmp = NULL;
	if ((ft_count_char(input[1], '=') != 1))
	{
		ft_putendl_fd(SETENV_USAGE, 2);
		return (-1);
	}
	tmp = ft_strsplit(input[1], '=');
	if (ft_arrlen((const char **)tmp) != 2)
	{
		ft_putendl_fd(SETENV_USAGE, 2);
		ft_arrfree(&tmp);
		return (-1);
	}
	ft_arrfree(&tmp);
	return (0);
}

static void	array_add_one(const char **input)
{
	size_t	count;
	char	**new;

	count = 0;
	new = NULL;
	fprintf(fd, "Fonction array_add_one :\n");
	fprintf(fd, "input = %s, %s\n", input[0], input[1]);
	if (!(new = (char**)malloc(sizeof(char*) * ft_arrlen((const char **)g_env) + 9))) // Si en dessous de 9 -> corrupted double linked list
		ft_malloc_error("builtin_setenv->array_add_one : error malloc", -1);
	fprintf(fd, "new = %p\ng_env = %p\n&new = %p\n&env = %p\n", new, g_env, &new, &g_env);
	while (g_env[count] != NULL)
	{
		fprintf(fd, "new[count] = %p\n&new[count] = %p\ng_env[count] = %p\n&g_env[count] = %p\n", new[count], &new[count], g_env, &g_env);
		new[count] = g_env[count];
		fprintf(fd, "new[count] = %p\n&new[count] = %p\ng_env[count] = %p\n&g_env[count] = %p\n", new[count], &new[count], g_env, &g_env);
		count++;
	}
	new[count] = ft_strdup(input[1]);
	new[++count] = NULL;
	free(g_env);
	g_env = new;
	fprintf(fd, "\nnew = %p\ng_env = %p\n&new = %p\n&env = %p\n", new, g_env, &new, &g_env);
}

int			ft_setenv(const char **input)
{
	int		count;
	int		len;

	fprintf(fd, "\nFonction ft_setenv :\n");
	if ((input == NULL) || (check_input(input) != 0))
		return (-1);
	count = 0;
	len = ft_strnlen(input[1], '=');
	while (g_env[count] != NULL)
	{
		if (ft_strncmp(input[1], g_env[count], len) == 0)
		{
			ft_strdel(&g_env[count]);
			g_env[count] = ft_strdup(input[1]);
			return (0);
		}
		count++;
	}
	array_add_one(input);
	return (0);
}

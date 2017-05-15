/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:21:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/11 15:31:17 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_input(const char **input)
{
	char	**tmp;

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

static void array_add_one(const char **input)
{
	int count;
	char **new;

	count = 0;
	new = (char**)malloc(sizeof(char*) * ft_arrlen((const char **)g_env) + 2);
	while (g_env[count] != NULL)
	{
		new[count] = g_env[count];
		count++;
	}
	new[count] = ft_strdup(input[1]);
	new[++count] = NULL;
	free(g_env);
	g_env = new;
}

int			ft_setenv(const char **input)
{
	int		count;
	int		len;

	if ((input == NULL) || (check_input(input) != 0))
		return (-1);
	count = -1;
	len = ft_strnlen(input[1], '=');
	while (g_env[++count] != NULL)
	{
		if (ft_strncmp(input[1], g_env[count], len) == 0)
		{
			ft_strdel(&g_env[count]);
			g_env[count] = ft_strdup(input[1]);
			return (0);
		}
	}
	array_add_one(input);
	return (0);
}

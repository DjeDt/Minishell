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
	int		n;
	int		count;
	char	**tmp;

	n = 0;
	count = 0;
	while ((input[1]) && (input[1][count++] != '\0'))
		input[1][count] == '=' ? n++ : 0;
	if (n != 1 || count < 2)
	{
		ft_putendl_fd(SETENV_USAGE, 2);
		return (-1);
	}
	tmp = ft_strsplit(input[1], '=');
	if (ft_array_len((const char **)tmp) != 2)
	{
		ft_putendl_fd(SETENV_USAGE, 2);
		ft_array_free(&tmp);
		return (-1);
	}
	ft_array_free(&tmp);
	return (0);
}

static void	array_add_one(const char **input)
{
	int		count;
	char	**new;

	count = 0;
	if (!(new = (char**)malloc(sizeof(char*) * ft_array_len((const char **)g_env) + 2)))
		ft_putendl_fd("error: not enought memory to malloc", 2);
	while (g_env[count] != NULL)
	{
		new[count] = ft_strdup(g_env[count]);
		count++;
	}
	new[count++] = ft_strdup(input[1]);
	new[count] = NULL;
	ft_array_free(&g_env);
	g_env = new;
}

int			ft_setenv(const char **input)
{
	int		count;

	if ((input == NULL) || (check_input(input) != 0))
		return (-1);
	count = -1;
	while (g_env[++count] != NULL)
	{
		if (ft_strcmp(input[1], g_env[count]) == 0)
		{
			ft_strdel(&g_env[count]);
			g_env[count] = ft_strdup(input[1]);
			return (0);
		}
	}
	array_add_one(input);
	return (0);
}

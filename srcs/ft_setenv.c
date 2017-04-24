/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:21:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/20 15:20:39 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_input(const char **input)
{
	int	n;
	int count;

	n = 0;
	count = -1;
	if (input == NULL)
		return (-1);
	while (input[1][++count] != '\0')
		input[1][count] == '=' ? n++ : 0;
	if (n != 1)
	{
		ft_putstrlen_fd(SETENV_USAGE, 2);
		return (-1);
	}
	return (0);
}

static void	array_add_one(const char **input)
{
	int		count;
	char	**new;

	count = 0;
	if (!(new = (char**)malloc(sizeof(char*) * ft_array_len(g_env) + 2)))
		ft_malloc_error();
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
	int		len;

	if ((input == NULL) || (check_input(input) != 0))
		return (-1);
	count = -1;
	len = ft_strnlen(input[1], '=');
	while (g_env[++count] != NULL)
	{
		if (ft_strncmp(input[1], g_env[count], len) == 0)
		{
			ft_memdel((void*)&g_env[count]);
			g_env[count] = ft_strdup(input[1]);
			return (0);
		}
	}
	array_add_one(input);
	return (0);
}

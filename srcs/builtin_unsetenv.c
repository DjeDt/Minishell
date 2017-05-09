/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:09:42 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/09 17:26:47 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int		check_input(const char **input)
{
	if (ft_array_len(input) != 2)
	{
		ft_putendl(UNSETENV_USAGE);
		return (-1);
	}
	return (0);
}

static	void	array_remove_one(const char *rm)
{
	int		count;
	int		count2;
	char	**new;
	char	*name;

	count = 0;
	count2 = 0;
	if (!(new = (char**)malloc(sizeof(char*) * ft_array_len((const char **)g_env))))
		ft_putendl("Malloc error");
	while (g_env[count] != NULL)
	{
		name = get_var_name(g_env[count]);
		if (ft_strncmp(name, rm, ft_strlen(rm)) != 0)
		{
			new[count2] = ft_strdup(g_env[count]);
			count2++;
		}
		ft_memdel((void*)&name);
		count++;
	}
	new[count2] = NULL;
	ft_array_free(&g_env);
	g_env = new;
}

int				ft_unsetenv(const char **input)
{
	int		count;
	int		len;

	count = 0;
	if (check_input(input) != 0)
		return (-1);
	len = ft_strlen(input[1]);
	while (g_env[count] != NULL)
	{
		if (ft_strncmp(g_env[count], input[1], len) == 0)
		{
			array_remove_one(input[1]);
			return (0);
		}
		count++;
	}
	return (0);
}

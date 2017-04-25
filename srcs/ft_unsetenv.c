/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:09:42 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/18 21:21:41 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int		check_input(const char **input)
{
	int n;
	int count;

	n = 0;
	count = -1;
	while (input[1][++count] != '\0')
		input[1][count] == '=' ? n++ : 0;
	return (0);
}

static	void	array_remove_one(char *rm)
{
	int		count;
	int		count2;
	char	**new;
	char	*name;

	count = 0;
	count2 = 0;
	if (!(new = (char**)malloc(sizeof(char*) * ft_array_len(g_env))))
		ft_putendl("Malloc error");
	while (g_env[count])
	{
		name = get_var_name(g_env[count]);
		if (ft_strcmp(name, rm))
		{
			new[count2] = ft_strdup(g_env[count]);
			count2++;
		}
		ft_memdel((void*)&name);
		count++;
	}
	new[count2] = NULL;
	g_env = new;
}

int				ft_unsetenv(const char **input)
{
	int		count;
	int		len;

	count = -1;
	check_input(input);
	len = ft_strlen(input[1]);
	if (input == NULL || input[2] != NULL)
	{
		ft_putendl_fd(UNSETENV_USAGE, 2);
		return (-1);
	}
	while (g_env[++count] != NULL)
	{
		if (ft_strncmp(g_env[count], input[1], len) == 0)
		{
			array_remove_one((char*)input[1]);
			return (0);
		}
	}
	return (0);
}

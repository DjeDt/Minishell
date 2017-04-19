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

static	int		check_input(char **input)
{
	int n;
	int count;

	n = 0;
	count = -1;
	while (input[1][++count] != '\0')
		input[1][count] == '=' ? n++ : 0;
	return (0);
}

static	void	array_remove_one(char *rm, char ***environ)
{
	int		count;
	int		count2;
	char	**new;
	char	*name;

	count = 0;
	count2 = 0;
	if (!(new = (char**)malloc(sizeof(char*) * ft_array_len(*environ))))
		ft_putendl("Malloc error");
	while ((*environ)[count])
	{
		name = get_var_name((*environ)[count]);
		if (ft_strcmp(name, rm))
		{
			new[count2] = ft_strdup((*environ)[count]);
			count2++;
		}
		ft_memdel((void*)&name);
		count++;
	}
	new[count2] = NULL;
	ft_array_free(environ);
	(*environ) = new;
}

int				ft_unsetenv(char **input, char ***ar_env)
{
	int		count;
	int		len;
	char	**tmp;

	count = -1;
	check_input(input);
	len = ft_strnlen(input[1], '=');
	tmp = (*ar_env);
	if (input == NULL || input[2] != NULL)
	{
		ft_putendl_fd(UNSETENV_USAGE, 2);
		return (-1);
	}
	while (tmp[++count] != NULL)
	{
		if (ft_strncmp(tmp[count], input[1], len) == 0)
		{
			array_remove_one(input[1], ar_env);
			return (0);
		}
	}
	return (0);
}

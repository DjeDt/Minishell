/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:21:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/18 20:49:34 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_input(char **input)
{
	int	n;
	int count;

	n = 0;
	count = -1;
	while (input[1][++count] != '\0')
		input[1][count] == '=' ? n++ : 0;
	if (n != 1 || input[2] != NULL)
	{
		ft_putstrlen_fd(SETENV_USAGE, 2);
		return (-1);
	}
	return (0);
}

static void	array_add_one(char *str, char ***ar_env)
{
	int		count;
	char	**new;

	count = 0;
	if (!(new = (char**)malloc(sizeof(char*) * ft_array_len(*ar_env) + 2)))
		ft_putendl("malloc error");
	while ((*ar_env)[count])
	{
		new[count] = ft_strdup((*ar_env)[count]);
		count++;
	}
	new[count++] = ft_strdup(str);
	new[count] = NULL;
	ft_array_free(ar_env);
	(*ar_env) = new;
}

int			ft_setenv(char **input, char ***ar_env)
{
	int		count;
	int		len;
	char	**tmp;

	count = -1;
	len = ft_strnlen(input[1], '=');
	tmp = (*ar_env);
	if ((input[1] == NULL) || (check_input(input) != 0))
		return (-1);
	while (tmp[++count])
	{
		if (ft_strncmp(input[1], tmp[count], len) == 0)
		{
			ft_memdel((void*)&tmp[count]);
			tmp[count] = ft_strdup(input[1]);
			return (0);
		}
	}
	array_add_one(input[1], ar_env);
	return (0);
}

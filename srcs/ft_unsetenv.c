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
}

static	void	array_remove_one(int ptr, char ***environ)
{
	char	**tmp;

	tmp = (*environ);
	ft_memdel((void*)&tmp[ptr]);
	while (tmp[ptr] != NULL)
	{
		tmp[ptr] = tmp[ptr + 1];
		ptr++;
	}
	tmp[ptr] = NULL;
}

int				ft_unsetenv(char **input, char ***ar_env)
{
	int		count;
	int		len;
	char	**tmp;

	count = -1;
	len = ft_strlen(input[1]);
	tmp = (*ar_env);
	if (input == NULL || input[2] != NULL)
	{
		ft_putendl_fd(UNSETENV_USAGE, 2);
		return (-1);
	}
	while (tmp[++count] != NULL)
	{
		if (ft_strncmp(tmp[count], input[1], len) == 0)
			array_remove_one(count, ar_env);
	}
	return (0);
}

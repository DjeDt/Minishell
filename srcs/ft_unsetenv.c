/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:09:42 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/18 15:21:41 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	new_tab(int ptr, char ***environ)
{
	char	**tmp;

	tmp = (*environ);
	while (tmp[ptr] != NULL)
	{
		free(tmp[ptr]);
		tmp[ptr] = ft_strdup(tmp[ptr + 1]);
		ptr++;
	}
	ft_array_print(tmp);
}

int				ft_unsetenv(char **input, char **ar_env)
{
	int count;
	int	len;

	count = -1;
	len = ft_strlen(input[1]);
	if (input == NULL || input[2] != NULL)
	{
		ft_putendl_fd(UNSETENV_USAGE, 2);
		return (-1);
	}
	while (ar_env[++count] != NULL)
	{
		if (ft_strncmp(ar_env[count], input[1], len) == 0)
			new_tab(count, &ar_env);
	}
	return (0);
}

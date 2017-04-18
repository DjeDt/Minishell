/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:21:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/18 15:15:43 by ddinaut          ###   ########.fr       */
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
		ft_putendl_fd(SETENV_USAGE, 2);
		return (-1);
	}
	return (0);
}

static char	**array_add_one(char *new, char ***ar_env)
{
	int		count;
	char	**tmp;
	char	**ret;

	count = -1;
	tmp = (*ar_env);
	if (!(ret = (char**)malloc(sizeof(char*) * ft_array_len(tmp) + 1)))
		return (NULL);
	while (tmp[++count] != NULL)
		ret[count] = ft_strdup(tmp[count]);
	ret[++count] = ft_strdup(new);
	ret[++count] = NULL;
	return (ret);
}

int			ft_setenv(char **input, char **ar_env)
{
	int		count;

	count = -1;
	if (input[1] == NULL)
		return (-1);
	check_input(input);
	while (ar_env[++count] != NULL)
	{
		if (ft_strncmp(input[1], ar_env[count], ft_strnlen(input[1], '=')) == 0)
		{
			ft_memdel((void*)&ar_env[count]);
			ar_env[count] = ft_strdup(input[1]);
			return (0);
		}
	}
	ar_env = array_add_one(input[1], &ar_env);
	return (0);
}

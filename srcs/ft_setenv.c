/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:21:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/07 17:11:47 by ddinaut          ###   ########.fr       */
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

static char	**ft_change_env(char ***env, char **input)
{
	int		count;
	char	**ret;
	char	**tmp;

	tmp = (*env);
	count = -1;
	if (!(ret = (char**)malloc(sizeof(char*) * ft_arraylen(tmp) + 1)))
		return (NULL);	// changer le retour et penser au free si malloc erreur
	while (tmp[++count] != NULL)
		ret[count] = ft_strdup(tmp[count]);
	ret[++count] = ft_strdup(input[1]);
	ft_arrayfree(&tmp);
	return (ret);
}

int		ft_setenv(char **input, char ***environ)
{
	int		count;
	char	**tmp;

	count = 0;
	tmp = (*environ);
	if (input == NULL || check_input(input) != 0)
		return (-1);
	while (tmp[count] != NULL)
	{
		if (ft_strncmp(tmp[count], input[1], ft_strnlen(input[1], '=')) == 0)
		{
			free(tmp[count]);
			tmp[count] = ft_strdup(input[1]);
			return (0);
		}
		count++;
	}
	tmp = ft_change_env(&tmp, input);
	return (0);
}

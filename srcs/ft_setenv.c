/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:21:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/30 17:05:02 by ddinaut          ###   ########.fr       */
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
	if (n >= 2 || input[2] != NULL || n < 1)
	{
		ft_putendl_fd(SETENV_USAGE, 2);
		return (-1);
	}
	return (0);
}

static int	name_len(char	*str)
{
	int count;

	count = 0;
	while ((str[count] != '\0') && (str[count] != '='))
		count++;
	return (count);
}

static	void	add_one(char ***base, char *add)
{
	int		count;
	char	**newtab;

	count = -1;
	if (!(newtab = (char**)malloc(sizeof(char*) * ft_tablen(*base) + 2)))
		return ;
	while (*base[++count] != NULL)
		newtab[count] = ft_strdup(*base[count]);
	newtab[count++] = ft_strdup(add);
	newtab[count] = NULL;
	while (--count >= 0)
		free(*base[count]);
	base = &newtab;
}

int		ft_setenv(char **input, char ***environ)
{
	int		count;

	count = 0;
	if (input == NULL || (check_input(input) != 0))
		return (-1);
	while (*environ[count] != NULL)
	{
		if (ft_strncmp(*environ[count], input[1], name_len(input[1])) == 0)
		{
			free(*environ[count]);
			*environ[count] = ft_strdup(input[1]);
			return (0);
		}
		count++;
	}
	add_one(environ, input[1]);
//	environ = ft_tabaddone(environ, input[1]);
	ft_tabprint((*environ));
	return (0);
}

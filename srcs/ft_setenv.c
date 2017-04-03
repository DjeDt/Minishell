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

static int	name_len(char	*str)
{
	int count;

	count = 0;
	while ((str[count] != '\0') && (str[count] != '='))
		count++;
	return (count);
}

int		ft_setenv(char **input, char **environ)
{
	int		count;
	int		count2;

	count = 0;
	count2 = 1;
	if (input == NULL)
		return (-1);
	while (input[count2] != NULL)
	{
		while (environ[count] != NULL)
		{
			if (ft_strncmp(environ[count], input[count2], name_len(input[count2])) == 0)
			{
				ft_strreplace(environ[count], input[count2]);
				break ;
			}
			count++;
		}
		environ = ft_tabjoin(environ, input[count2]);
		count2++;
	}
	ft_putstrlen("environ = \n");
	ft_tabprint(environ);
	return (0);
}

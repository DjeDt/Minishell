/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/07 14:12:39 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	arg_check(char **input)
{
	int				count;
	int				count2;
	unsigned int	flags;
	char			*mask;

	count = 0;
	flags = 0;
	mask = ft_strdup("i");
	while (input[++count])
	{
		count2 = 1;
		while (input[count][count2] != '\0' && input[count][0] == '-')
		{
			if (ft_strchr(mask, input[count][count2]) != NULL)
				flags |= (1 << (ft_strchr(mask, input[count][count2]) - mask));
			else
			{
				ft_arg_error(input[count][count2]);
				return (-1);
			}
			count2++;
		}
	}
	ft_memdel((void*)&mask);
	return (flags);
}

static	int option_i(char **input)
{
	int		count;
	int		count2;
	char	**tmp;

	count = 2;
	count2 = 0;
	if (!(tmp = (char**)malloc(sizeof(char*) * ft_arraylen(input) - 2)))
		return (-1);
	while (input[count] != NULL)
	{
		tmp[count2] = ft_strdup(input[count]);
		count++;
		count2++;
	}
	ft_arrayprint(tmp);
	ft_arrayfree(&tmp);
	return (0);
}

int			ft_env(char **input, char ***environ)
{
	int		flags;
	char	**tmp;

	flags = arg_check(input);
	tmp = (*environ);
	if (flags == -1)
		return (-1);
	if (flags & FLAG_1)
		option_i(input);
	else
		ft_arrayprint(tmp);
	return (0);
}

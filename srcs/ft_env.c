/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/30 16:38:41 by ddinaut          ###   ########.fr       */
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
	free(mask);
	return (flags);
}

static unsigned int option_i(char **input)
{
	int		count;
	int		count2;
	char	**tmp;

	count = 2;
	count2 = 0;
	tmp = NULL;
	while (input[count] != NULL)
	{
		if (!(tmp = (char**)malloc(sizeof(char*) * ft_tablen(input) - 2)))
			return (-1);
		tmp[count2] = ft_strdup(input[count]);
//		ft_putendl(tmp[count2]);
		count++;
		count2++;
	}
	ft_tabprint(tmp);
	return (0);
}

int			ft_env(char **input, char **environ)
{
	int		flags;

	flags = arg_check(input);
	if (flags == -1)
		return (-1);
	if (flags & FLAG_1)
		option_i(input);
	else
		ft_tabprint(environ);
	return (0);
}

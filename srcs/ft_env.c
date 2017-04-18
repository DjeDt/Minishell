/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/18 15:14:38 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	arg_check(char **input)
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

static int	env_option_i(char **input, char ***ar_env)
{
	(void)input;
	(void)ar_env;
	ft_putendl("option i");
	return (0);
}

int			ft_env(char **input, char **ar_env)
{
	int		flags;

	flags = arg_check(input);
	if (flags == -1)
		return (-1);
	if (flags & FLAG_1)
		env_option_i(input, &ar_env);
	else
		ft_array_print(ar_env);
	return (0);
}

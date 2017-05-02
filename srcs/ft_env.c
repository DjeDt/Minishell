/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/02 18:56:02 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	arg_check(const char **input)
{
	int				count;
	int				count2;
	unsigned int	flags;
	char			*mask;

	count = 0;
	flags = 0;
	mask = ft_strdup("i");
	while (input[++count] && input[count][0] == '-')
	{
		count2 = 1;
		while (input[count][count2] != '\0' && input[count][0] == '-')
		{
			if (ft_strchr(mask, input[count][count2]) != NULL)
				flags |= (1 << (ft_strchr(mask, input[count][count2]) - mask));
			else
			{
				ft_arg_error(input[count][count2]);
				ft_memdel((void*)&mask);
				return (-1);
			}
			count2++;
		}
	}
	ft_memdel((void*)&mask);
	return (flags);
}

static int	env_option_i(const char **input)
{
	ft_putendl("OPTION I");
	(void)input;
	return (0);
}

int			ft_env(const char **input)
{
	int		flags;

	flags = arg_check(input);
	if (flags == -1)
		return (-1);
	else if (flags & FLAG_1)
		env_option_i(input);
	else if (ft_array_len(input) > 1)
		ft_launch_prog((char**)input + 1);
	else
		ft_array_print((const char **)g_env);
	return (0);
}

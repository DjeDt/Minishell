/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/17 19:26:12 by ddinaut          ###   ########.fr       */
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

static	int env_option_i(char **input)
{
	(void)input;
	ft_putendl("option i");
	return (0);
}

int		ft_env(char **input, t_env **list)
{
	int		flags;
	t_env	*tmp;

	flags = arg_check(input);
	tmp = (*list);
	if (flags == -1)
		return (-1);
	if (flags & FLAG_1)
		env_option_i(input);
	else
		list_print(&tmp);
	return (0);
}

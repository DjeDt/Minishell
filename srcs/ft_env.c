/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/27 17:21:48 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

static unsigned int	arg_check(char **input)
{
	int				count;
	int				count2;
	unsigned int	flags;
	const char		*mask;

	count = 0;
	flags = 0;
	mask = "i";
	while (input[++count])
	{
		count2 = 1;
		while (input[count][count2] != '\0' && input[count][0] == '-')
		{
			if (ft_strchr(mask, input[count][count2]) != NULL)
				flags |= (1 << (ft_strchr(mask, input[count][count2]) - mask));
			else
				ft_arg_error(input[count][count2]);
			count2++;
		}
	}
	return (flags);
}

void				ft_env(char **input)
{
	int flags;

	flags = arg_check(input);
	if (flags & )
	{
		ft_putendl("no flag");
		ft_tabprint(environ);
	}
	if (flags & FLAG_1)
		ft_putendl("option ok");
}

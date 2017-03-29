/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/28 16:33:04 by ddinaut          ###   ########.fr       */
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
			{
				ft_arg_error(input[count][count2]);
				return (-1);
			}
			count2++;
		}
	}
	return (flags);
}

static unsigned int arg_check2(char **input)
{
	int count;

	count = 0;
	while (input[++count])
	{
		while (input[count][0] == '-')
			count++;
		ft_putendl(input[count]);
	}
	return (0);
}

void				ft_env(char *input)
{
	int		count;
	int		flags;
	char	**tmp;

	tmp = ft_split_whitespaces(input);
	flags = arg_check(tmp);
	if (flags == -1)
		return ;
	if (flags & FLAG_1)
		arg_check2(tmp);
	else
		ft_tabprint(environ);
	count = -1;
	while (tmp[++count])
		ft_memdel((void*)tmp[count]);
	ft_memdel((void**)tmp[count]);
	tmp = NULL;
	exit (0);
}

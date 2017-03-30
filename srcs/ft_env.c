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

void				ft_env(char *input, char **environ)
{
	int		count;
	int		flags;
	char	**tmp;

	tmp = ft_split_whitespaces(input);
	flags = arg_check(tmp);
	if (flags == -1)
		return ;
	if (flags & FLAG_1)
		option_i(tmp);
	else
		ft_tabprint(environ);
	count = -1;
	while (tmp[++count])
		free(tmp[count]);
	free(tmp);
	tmp = NULL;
	exit (0);
}

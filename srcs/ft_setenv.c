/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:21:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/17 19:38:26 by ddinaut          ###   ########.fr       */
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
	if (n != 1 || input[2] != NULL)
	{
		ft_putendl_fd(SETENV_USAGE, 2);
		return (-1);
	}
	return (0);
}

int		ft_setenv(char **input, t_env **list)
{
	t_env	*tmp;

	if (input[1] == NULL)
		return (-1);
	check_input(input);
	tmp = (*list);
	while (tmp->next != NULL)
	{
		if (ft_strncmp(input[1], tmp->name, ft_strnlen(input[1], '=')) == 0)
		{
			ft_memdel((void*)&tmp->name);
			tmp->name = ft_strdup(input[1]);
			return (0);
		}
		tmp = tmp->next;
	}
	ft_add_lst_env(input[1], ft_strlen(input[1]), &tmp);
	return (0);
}

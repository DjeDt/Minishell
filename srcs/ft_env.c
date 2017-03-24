/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:39 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/24 14:49:44 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char **environ;

void		ft_env(char **input)
{
	if (ft_strncmp(input[1], "-i", 2) == 0)
	{
		ft_putendl("on lance les options");
	}
	else if (input[1] == NULL)
	{
		ft_putendl("tabprint");
		ft_tabprint(environ);
	}
}

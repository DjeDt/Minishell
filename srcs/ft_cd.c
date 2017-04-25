/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:46:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/20 17:48:30 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cd(const char **input)
{
	int	ret;

	if (input[1] == NULL)
		return (-1);
	if (ft_strncmp(input[1], "~", 1) == 0)
		ret = chdir(get_var_value(g_env, "HOME"));
	else
		ret = chdir(input[1]);
	if (ret == -1)
	{
		ft_putstrlen(input[1]);
		ft_putendl(" not found");
		return (-1);
	}
	return (0);
}

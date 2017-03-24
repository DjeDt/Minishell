/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:01:30 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/24 14:44:00 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_check_input(char *cmd)
{
	char **tmp;

	tmp = ft_split_whitespaces(cmd);
	if (ft_strncmp(tmp[0], "env", 3) == 0)
		ft_env(tmp);
	ft_tabfree(tmp);
	return (NULL);
}

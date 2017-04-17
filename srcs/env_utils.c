/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:42:30 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/24 14:43:09 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

void	ft_env_to_lst(t_env **list)
{
	int count;

	count = -1;
	while (environ[++count] != NULL)
		ft_add_lst_env(environ[count], ft_strlen(environ[count]), list);
}

char	*ft_get_env_var(char *tf, t_env **list)
{
	t_env *tmp;

	tmp = (*list);
	while ((tmp->next != NULL) && (ft_strncmp(tf, tmp->name, ft_strlen(tf)) != 0))
		tmp = tmp->next;
	return (tmp->name);
}

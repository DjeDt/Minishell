/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:42:30 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/17 18:24:13 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

void	ft_env_to_lst(t_env **list)
{
	int		count;

	count = -1;
	while (environ[++count] != NULL)
		ft_add_lst_env(environ[count], ft_strlen(environ[count]), list);
}

char	*get_var_name(const char *tf, t_env **list)
{
	t_env	*tmp;

	tmp = (*list);
	if (tf == NULL)
		return (NULL);
	while ((tmp->next != NULL) && (ft_strncmp(tf, tmp->name, ft_strlen(tf)) != 0))
		tmp = tmp->next;
	free(tmp);
	return (tmp->name);
}

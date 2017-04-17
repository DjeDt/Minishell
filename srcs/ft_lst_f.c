/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:23:43 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/17 19:32:33 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_lst_env(t_env **list)
{
	t_env **tmp;
	t_env *nxt;

	tmp = list;
	nxt = NULL;
	while (*list)
	{
		free((*tmp)->name);
		nxt = (*list)->next;
		free(*list);
		(*list) = nxt;
	}
}

void	ft_add_lst_env(char *data, int len, t_env **list)
{
	t_env	*tmp;

	tmp = NULL;
	if (!(*list))
		(*list) = ft_create_lst_env(data, len);
	else
	{
		tmp = (*list);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_create_lst_env(data, len);
	}
}

t_env	*ft_create_lst_env(char *data, int len)
{
	t_env	*new;

	if (!(new = (t_env*)malloc(sizeof(t_env) * 1)))
		return (NULL);
	if (data == NULL)
	{
		new->name = NULL;
		new->len = 0;
	}
	else
	{
		if (!(new->name = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ft_memcpy((char*)new->name, data, len + 1);
		new->len = len;
	}
	new->next = NULL;
	return (new);
}

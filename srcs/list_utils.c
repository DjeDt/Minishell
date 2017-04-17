/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:24:20 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/17 18:37:47 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_print(t_env **list)
{
	t_env *tmp;

	tmp = (*list);
	while (tmp->next != NULL)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

int		list_len(t_env **list)
{
	int		count;
	t_env	*tmp;

	count = -1;
	tmp = (*list);
	while (tmp->next != NULL && ++count)
		tmp = tmp->next;
	free(tmp);
	return (count);
}

char	**list_to_array(t_env **list)
{
	int		count;
	char	**ret;
	t_env	*tmp;

	count = -1;
	if (!(ret = (char**)malloc(sizeof(char*) * list_len(list))))
		return (NULL);
	tmp = (*list);
	while (tmp->next != NULL)
	{
		ret[++count] = ft_strdup(tmp->name);
		tmp = tmp->next;
	}
	ret[++count] = NULL;
	return (ret);
}

t_env	*array_to_list(char **ar)
{
	int		count;
	t_env	*list;

	count = -1;
	list = NULL;
	while (ar[++count] != NULL)
		ft_add_lst_env(ar[count], ft_strlen(ar[count]), &list);
	return (list);
}

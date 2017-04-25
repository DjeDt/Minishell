/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:42:30 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/25 17:23:54 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern	char	**environ;

char			**get_environ(void)
{
	return (ft_array_cpy(environ));
}

char			*get_var_name(char *str)
{
	char	*ret;
	char	*pos;
	int		count;

	ret = NULL;
	if ((pos = ft_strchr(str, '=')))
	{
		count = 0;
		if (!(ret = (char*)malloc(pos - str + 1)))
			return (NULL);
		while (str[count] != '=')
		{
			ret[count] = str[count];
			count++;
		}
		ret[count] = '\0';
	}
	return (ret);
}

char			*get_var_value(char **ar_env, const char *tf)
{
	size_t	count;
	char	*tmp;
	char	tc;

	count = 0;
	tmp = NULL;
	while (ar_env[count] != NULL)
	{
		if ((tmp = ft_strchr(ar_env[count], '=')))
		{
			tc = *tmp;
			*tmp = 0;
			if (!ft_strcmp(tf, ar_env[count]))
			{
				*tmp = tc;
				return (tmp + 1);
			}
			(*tmp) = tc;
			count++;
		}
	}
/*	ft_memdel((void*)&tmp);  -- segfault si actif -- */
	return (NULL);
}

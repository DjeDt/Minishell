/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:42:30 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/27 19:59:17 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern	char	**environ;

char			**get_environ(void)
{
	char **tmp;

	tmp = ft_array_cpy((const char **)environ);
	return (tmp);
}

char			*get_var_name(char *str)
{
	char	*ret;

	ret = NULL;
	if (str != NULL)
		ret = ft_strndup(str, ft_strnlen(str, '='));
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
		else
			count++;
	}
	return (NULL);
}

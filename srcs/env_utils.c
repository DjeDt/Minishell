/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:42:30 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/18 16:22:18 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern	char	**environ;

char			**get_environ(void)
{
	int		count;
	char	**tmp;

	count = 0;
	if (!(tmp = (char**)malloc(sizeof(char*) * ft_array_len(environ) + 1)))
		return (NULL);
	while (environ[count] != NULL)
	{
		tmp[count] = ft_strdup(environ[count]);
		count++;
	}
	tmp[count] = NULL;
	return (tmp);
}

char			*get_var_name(const char *tf, char ***ar_env)
{
	int		count;
	char	**tmp;

	count = 0;
	tmp = (*ar_env);
	while (tmp[++count] != NULL)
	{
		if (ft_strncmp(tf, tmp[count], ft_strlen(tf)) == 0)
			return (ft_strchr(tmp[count], '=') + 1);
	}
	return (NULL);
}

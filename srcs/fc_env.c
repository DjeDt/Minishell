/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:42:30 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/24 14:43:09 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**environ;

char		**ft_cpyenv(void)
{
	size_t	count;
	char	**ret;

	count = -1;
	if (environ == NULL)
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(char*) * ft_arraylen(environ))))
		return (NULL);
	while (environ[++count])
		ret[count] = ft_strdup(environ[count]);
	return (ret);
}

char		*ft_getenv(char *str)
{
	int		count;

	count = -1;
	if (!str)
		return (NULL);
	while (environ[++count] != NULL)
	{
		if (ft_strncmp(environ[count], str, ft_strlen(str)) == 0)
			return (ft_strchr(environ[count], '=') + 1);
	}
	return (NULL);
}

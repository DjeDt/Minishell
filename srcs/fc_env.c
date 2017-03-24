/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:42:30 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/24 10:45:19 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char **environ;

char		**ft_get_full_env(void)
{
	char	**ret;

	if ((*environ) == NULL)
		return (NULL);
	ret = ft_tabcpy(environ);
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

char		*ft_getprog(char **av, char *prog)
{
	int		count;
	char	*tmp;
	char	**path;

	count = -1;
	tmp = NULL;
	path = ft_getpath(ft_getenv("PATH"));
	while (path[++count])
	{
		tmp = ft_strjoin(path[count], "/");
		execve(ft_strjoin(tmp, prog), av, NULL);
		free(tmp);
		tmp = NULL;
	}
	ft_tabfree(path);
	return (NULL);
}

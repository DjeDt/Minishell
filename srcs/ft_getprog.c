/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:03:10 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/23 17:53:45 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getprog(char **av, char **path, char *prog)
{
	int count;
	char *tmp;

	count = -1;
	tmp = NULL;
	while (path[++count])
	{
		tmp = ft_strjoin(path[count], "/");
		execve(ft_strjoin(tmp, prog), av, NULL);
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

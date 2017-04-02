/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:21:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/30 17:05:02 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_setenv(char **str, char **environ)
{
	/*
	int count;

	count = 0;
	while (!ft_strcmp(name, environ[count]))
		count++;
	if (environ[count] == NULL)
		exit (-1);
	free(environ[count]);
	environ[count] = NULL;
	environ[count] = ft_strjoin(name, ft_strjoin("=", value));
	free(name);
	free(value);
	*/
	ft_putendl("ft_setenv");
	(void)str;
	(void)environ;
	return (0);
}

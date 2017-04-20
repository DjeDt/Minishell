/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:46:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/20 17:48:30 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cd(char **input, char ***environ)
{
	int			fd;
	struct stat	s_stat;

	(void)environ;
	fd = open(input[1], O_RDONLY);
	chdir(input[1]);
	fstat(fd, &s_stat);
	return (0);
}

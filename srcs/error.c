/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:45:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/17 14:35:49 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_arg_error(char c)
{
	ft_putstrlen_fd("env: option invalide -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd(ENV_USAGE, 2);
}

void	ft_malloc_error(void)
{
	ft_putendl_fd("Error malloc, abort prog", 2);
	exit (-1);
}

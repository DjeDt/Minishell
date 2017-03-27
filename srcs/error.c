/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:45:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/27 17:14:59 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_arg_error(char c)
{
	ft_putstrlen("env: option invalide -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl(ENV_USAGE);
	exit (-1);
}

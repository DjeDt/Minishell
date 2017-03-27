/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 20:45:51 by ddinaut           #+#    #+#             */
/*   Updated: 2017/03/27 20:51:00 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.c"

static s_builtin	ft_init_builtin(void)
{
	static s_builtin built[]{
		{ "env", NULL},
		{ "setenv", NULL},
		{ "unsetenv", NULL},
		{ "echo", NULL},
		{ "cd", NULL},
		{ "exit", NULL}
	}
}

void	ft_test(void)
{
	s_builtin built;

	built = ft_init_builtin();
}

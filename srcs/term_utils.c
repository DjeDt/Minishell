/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:15:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/18 12:23:54 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_signal(int sig)
{
	(void)sig;
	ft_putchar('\n');
	print_prompt();
}

void	mode_raw(void)
{
	struct termios term;

	term.c_iflag &= ~(IXON);
	term.c_lflag &= ~(ISIG);
	term.c_lflag &= ~(ICANON);
	tcgetattr(STDIN_FILENO, &term);
}

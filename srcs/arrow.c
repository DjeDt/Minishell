/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:15:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/18 12:23:54 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mode_raw(void)
{
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_iflag &= ~(IXON);
	term.c_lflag &= ~(ISIG);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
}

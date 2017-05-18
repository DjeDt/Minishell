/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:15:48 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/11 19:15:57 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>

#include <termios.h>
#include <unistd.h>

void	mode_raw(void)
{
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);

	term.c_iflag &= ~(IXON); // Inhibe le controle de flux
	term.c_lflag &= ~(ISIG); // Pour virer les signaux comme ctrl+c

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term); // pour tout cacher
}

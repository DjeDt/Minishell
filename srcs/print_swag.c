/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_swag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:57:47 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/18 12:25:32 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_launch(void)
{
	ft_putstr("\033[0;32m");
	ft_putendl("        .__       .__       .__           .__  .__   ");
	ft_putendl("  _____ |__| ____ |__| _____|  |__   ____ |  | |  |  ");
	ft_putendl(" /     \\|  |/    \\|  |/  ___/  |  \\_/ __ \\|  | |  |  ");
	ft_putendl("|  Y Y  \\  |   |  \\  |\\___ \\|   Y  \\  ___/|  |_|  |__");
	ft_putendl("|__|_|  /__|___|  /__/____  >___|  /\\___  >____/____/");
	ft_putendl("      \\/        \\/        \\/     \\/     \\/           ");
	ft_putstr("\033[0;m");
	ft_putendl("\033[0;31m[djelali.dinaut@gmail.com] - [minishell]\n\033[0;m");
}

void	print_prompt(void)
{
	ft_putstr("\033[32;m");
	ft_putstr("$> ");
	ft_putstr("\033[0;m");
}

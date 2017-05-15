#include "minishell.h"

void	print_launch(void)
{
	ft_putendl("\033[0;32m        .__       .__       .__           .__  .__   ");
	ft_putendl("  _____ |__| ____ |__| _____|  |__   ____ |  | |  |  ");
	ft_putendl(" /     \\|  |/    \\|  |/  ___/  |  \\_/ __ \\|  | |  |  ");
	ft_putendl("|  Y Y  \\  |   |  \\  |\\___ \\|   Y  \\  ___/|  |_|  |__");
	ft_putendl("|__|_|  /__|___|  /__/____  >___|  /\\___  >____/____/");
	ft_putendl("      \\/        \\/        \\/     \\/     \\/           \033[0;m");
	ft_putendl("\033[0;31m[djelali.dinaut@gmail.com] - [minishell]\n\033[0;m");
}

void	print_prompt(void)
{
	ft_putstr("$> ");
}
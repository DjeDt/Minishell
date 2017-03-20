#include "minishell.h"
/*
static void print_tab(char **tab)
{
	int		count;

	count = -1;
	while (tab[count + 1])
		ft_putendl(tab[++count]);
}
*/
static char	**ft_set_env(void)
{
	char **tab;

	tab = (char**)malloc(sizeof(char*) * 3 + 1);
	tab[0] = "PATH";
	tab[1] = "ENV2";
	tab[2] = "ENV3";
	tab[3] = 0;

	return (tab);
}

int		main(int argc, char **argv)
{
	int		count;
	char	**tab;

	count = 1;
	tab = ft_set_env();
	(void)argc;
	while (count)
	{
		ft_putstrlen("$user> ");
		get_next_line(0, argv);
//		print_tab(ft_split_whitespaces(*argv));
		ft_get_env(tab, "PATH");
	}
	return (0);
}

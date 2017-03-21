#include "minishell.h"

static void print_tab(char **tab)
{
	int		count;

	count = -1;
	while (tab[++count])
		ft_putendl(tab[count]);
}

static char	**ft_set_env(void)
{
	char **tab;

	tab = (char**)malloc(sizeof(char*) * 5 + 1);
	tab[0] = "PATH = 1";
	tab[1] = "env = 2";
	tab[2] = "truc = 3";
	tab[3] = "test = 4";
	tab[4] = "ok = 5";
	tab[5] = "bla = 6";
	tab[6] = 0;

	return (tab);
}

int		main(int argc, char **argv)
{
	int		count;
	char	**test;
	char	**recup;

	count = 1;
	recup = NULL;
	test = ft_set_env();
	if (argc > 0)
	{
		while (count)
		{
			ft_putstrlen("\n$user--> ");
			get_next_line(1, argv);
			recup = ft_split_whitespaces(*argv);
			ft_putstrlen("recup = ");
			print_tab(recup);
			ft_putstrlen("get env = ");
			ft_putstrlen(ft_get_env(test, "test"));
		}
	}
	(void)test;
	return (0);
}

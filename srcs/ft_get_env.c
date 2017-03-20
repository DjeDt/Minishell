#include "minishell.c"

char	*ft_get_env(const char **tab, char *env)
{
	int count;
	int count2;

	count = 0;
	while (!ft_strstr(tab[count], env))
		count++;
	return (tab[count])
}

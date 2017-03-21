#include "minishell.h"

char	*ft_get_env(char **tab, char *env)
{
	int count;

	count = -1;
	if (!env)
		return (NULL);
	while (tab[++count])
	{
		ft_putendl("debut boucle");
		if (ft_strcmp(tab[count], env))
			return (ft_strchr((char*)tab[count], '='));
		ft_putendl("fin boucle");
	}
	return (NULL);
}

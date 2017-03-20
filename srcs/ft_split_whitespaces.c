#include "minishell.h"

static int		delimiteurs(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n'))
		return (1);
	return (0);
}

static int		ft_count(char *str)
{
	int i;

	i = 0;
	while (!(delimiteurs(str[i])) && str[i])
		i++;
	return (i);
}

static int		nbr_mots(char *str)
{
	int i;
	int nombremot;

	i = 0;
	nombremot = 0;
	while (str[i])
	{
		while ((delimiteurs(str[i])))
			i++;
		if (str[i] != 0)
		{
			while ((!delimiteurs(str[i])) && str[i])
				i++;
			nombremot++;
		}
	}
	return (nombremot);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		taille;
	int		nbmot;
	char	**tab;

	i = 0;
	j = 0;
	taille = 0;
	nbmot = nbr_mots(str);
	tab = (char**)malloc(sizeof(char*) * (nbmot + 1));
	while (j < nbmot)
	{
		while ((delimiteurs(str[i])))
			i++;
		taille = ft_count(&str[i]);
		tab[j] = (char*)malloc(sizeof(char) * (taille));
		tab[j] = ft_strncpy(tab[j], str + i, taille);
		i += taille;
		tab[j][taille] = '\0';
		j++;
	}
	tab[j] = 0;
	return (tab);
}

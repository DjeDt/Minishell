/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:54:38 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/27 15:50:53 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	delimiteurs(char c)
{
	if (c == ':' || c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static int	ft_count(char *str)
{
	int i;

	i = 0;
	while (!(delimiteurs(str[i])) && str[i])
		i++;
	return (i);
}

static int	nbr_mots(char *str)
{
	int i;
	int nombremot;

	i = 0;
	nombremot = 0;
	if (!str)
		return (0);
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

static char	*cpy(int j, int i, char *dst, char *src)
{
	if (!(dst = (char*)malloc(sizeof(char) * j + 1)))
		return (NULL);
	dst = ft_strncpy(dst, src + i, j);
	dst[j] = '\0';
	return (dst);
}

char		**split_path(char *str)
{
	int		i;
	int		j;
	int		taille;
	int		nbmot;
	char	**tab;

	i = 0;
	j = -1;
	taille = 0;
	nbmot = nbr_mots(str);
	if (!(tab = (char**)malloc(sizeof(char*) * (nbmot + 1))))
		return (NULL);
	while (++j < nbmot)
	{
		while ((delimiteurs(str[i])))
			i++;
		taille = ft_count(&str[i]);
		tab[j] = cpy(taille, i, tab[j], str);
		i += taille;
	}
	tab[j] = 0;
	return (tab);
}

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

/* Variables d'environnement */

/* */

char		**ft_split_whitespaces(char *str);
char		*ft_get_env(char **tab, char *env);

#endif

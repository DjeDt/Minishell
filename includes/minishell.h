#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

/* Variables d'environnement */
/* */

char		**ft_split_whitespaces(char *str);

char		**ft_getpath(char *str);
char		**ft_get_full_env(void);
char		*ft_getenv(char *str);
char		*ft_getprog(char **av, char *prog);


#endif
















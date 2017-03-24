#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

char		**ft_split_whitespaces(char *str);

char		**ft_getpath(char *str);
char		**ft_cpyenv(void);
char		*ft_getenv(char *str);
void		ft_env(char **input);

char		*ft_getprog(char **av);

char		*ft_check_input(char *cmd);

#endif



















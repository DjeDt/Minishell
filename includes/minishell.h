#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# define flg_env "i"
# define env_use "usage: env [-"flg_env"] [file...]\n"

// Pour wait :
# include <sys/types.h>
# include <sys/wait.h>
// fin de wait

char		**ft_split_whitespaces(char *str);

char		**ft_getpath(char *str);
char		**ft_cpyenv(void);
char		*ft_getenv(char *str);
void		ft_env(char **input);

char		*ft_getprog(char **av);

char		*ft_check_input(char *cmd);

#endif

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

/* Env error */
# define ENV_USAGE "usage: env [-i] [name=value]... [utility [argument...]]\n"

/* Sous debian */
# include <sys/types.h>
# include <sys/wait.h>

typedef struct	s_builtin
{
	const char	*ft;
	int			(*func)(char **, char **);
}test;

# define FLAG_0 0
# define FLAG_1 (1 << 0)
# define FLAG_2 (1 << 1)
# define FLAG_3 (1 << 2)
# define FLAG_4 (1 << 3)
# define FLAG_5 (1 << 4)

/* Gestion d'environnement */
char		**ft_getpath(char *str);
char		**ft_cpyenv(void);
char		*ft_getenv(char *str);

char		*ft_getprog(char **av);

/* Gestion d'erreurs */
void		ft_arg_error(char c);

/* Builtins */
int			ft_echo(char **input, char **environ);
int			ft_env(char **input, char **environ);
int			ft_setenv(char **name, char **environ);

#endif

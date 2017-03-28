#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# define ENV_USAGE "usage: env [-i] [name=value]... [utility [argument...]]\n"

/* sous debian
# include <sys/types.h>
# include <sys/wait.h>
*/

typedef struct	s_builtin
{
	const char	*ft;
	void		(*func)(char**);
}test;

# define FLAG_0 0
# define FLAG_1 (1 << 0)
# define FLAG_2 (1 << 1)
# define FLAG_3 (1 << 2)
# define FLAG_4 (1 << 3)
# define FLAG_5 (1 << 4)

char		**ft_getpath(char *str);
char		**ft_cpyenv(void);
char		*ft_getenv(char *str);
void		ft_env(char **input);

char		*ft_getprog(char **av);

void		ft_arg_error(char c);


#endif

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

/* Env error */
# define ENV_USAGE "usage: env [-i] [name=value]... [utility [argument...]]\n"
/* Setenv error*/
# define SETENV_USAGE "usage: setenv [NAME=value]\n"
/* Unsetenv error */
# define UNSETENV_USAGE "usage: unsetenv [NAME]\n"

/* Sous debian */
# include <sys/types.h>
# include <sys/wait.h>

# define FLAG_0 (0)
# define FLAG_1 (1 << 0)
# define FLAG_2 (1 << 1)
# define FLAG_3 (1 << 2)
# define FLAG_4 (1 << 3)
# define FLAG_5 (1 << 4)

/* Pointeurs sur fonctions */
typedef struct	s_builtin
{
	const char	*ft;
	int			(*func)(char **, char ***);
}s_builtin;

typedef struct	s_env
{
	char	*name;
	int		len;
	struct s_env	*next;
}t_env;

/* Gestion de listes */
void		list_print(t_env **list);
int			list_len(t_env **list);
char		**list_to_array(t_env **list);
t_env		*array_to_list(char **array);

/* Gestion d'environnement */
void		ft_free_lst_env(t_env **list);
void		ft_add_lst_env(char *data, int len, t_env **list);
t_env		*ft_create_lst_env(char *data, int len);

void		ft_env_to_lst(t_env **list);
char		*get_env_var(char *tf, t_env **list);
int			ft_getprog(char **av);

/* Gestion d'erreurs */
void		ft_arg_error(char c);

/* Builtins */
int			ft_echo(char **input, char ***environ);
int			ft_env(char **input, char ***environ);
int			ft_setenv(char **input, char ***environ);
int			ft_unsetenv(char **input, char ***environ);

#endif

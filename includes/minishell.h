#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/stat.h>
# include <unistd.h>


/* Sous debian */
# include <sys/types.h>
# include <sys/wait.h>



/* Env error */
# define ENV_USAGE "usage: env [-i] [name=value]... [utility [argument...]]\n"
/* Setenv error*/
# define SETENV_USAGE "usage: setenv [NAME=value]\n"
/* Unsetenv error */
# define UNSETENV_USAGE "usage: unsetenv [NAME]\n"

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

/* Gestion d'environnement */
char		**get_environ(void);
char		**split_path(char *str);
char		*get_var_name(char *str);
char		*get_var_value(char **ar_env, const char *tf);

/* Gestion d'erreurs */
void		ft_arg_error(char c);
void		ft_malloc_error(void);

/* Builtins */
int			ft_echo(char **input, char ***ar_env);
int			ft_env(char **input, char ***ar_env);
int			ft_setenv(char **input, char ***ar_env);
int			ft_unsetenv(char **input, char ***ar_env);
int			ft_exit(char **input, char ***ar_env);
int			ft_cd(char **input, char ***environ);

/* Others */
int			ft_launch_prog(char **av, char **env);

#endif

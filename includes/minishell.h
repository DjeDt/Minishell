#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/stat.h>
# include <unistd.h>

/* Pour le mode raw*/
# include <sys/termios.h>

/* Pour gerer les signaux claviers */
# include <signal.h>

/* Sous debian */
# include <sys/types.h>
# include <sys/wait.h>

/* Env error */
# define ENV_USAGE "usage: env [-i] [name=value]... [utility [argument...]]"
/* Setenv error*/
# define SETENV_USAGE "usage: setenv [NAME=value]"
/* Unsetenv error */
# define UNSETENV_USAGE "usage: unsetenv [NAME]"
/* Cd error */
# define CD_USAGE "usage: cd [path]"

# define FLAG_0 (0)
# define FLAG_1 (1 << 0)
# define FLAG_2 (1 << 1)
# define FLAG_3 (1 << 2)
# define FLAG_4 (1 << 3)
# define FLAG_5 (1 << 4)

/* int global pour le log */
# include <stdio.h>
# include <unistd.h>

/* Globale env */
char			**g_env;

/* Pointeurs sur fonctions */
typedef struct	s_builtin
{
	const char	*ft;
	int			(*func)(const char **);
}s_builtin;

/* Gestion d'environnement */
void		get_environ(void);
char		**split_path(char *str);
char		*get_var_name(char *str);
char		*get_var_value(const char *tf);

/* Gestion d'erreurs */
void		ft_malloc_error(char *str, int ret);
int			arg_error(char *str, char *usage, char c);
void		error_bin(const char *str);

/* Builtins */
int			ft_echo(const char **input);
int			ft_env(const char **input);
int			ft_setenv(const char **input);
int			ft_unsetenv(const char **input);
int			ft_exit(const char **input);
int			ft_cd(const char **input);

/* Others */
int			read_line(const int fd, char **line);
int			ft_launch_prog(const char **av);

/* Edition de ligne */
void		mode_raw(void);
void		get_signal(int signal);

/* print func */
void		print_prompt(void);
void		print_launch(void);

#endif

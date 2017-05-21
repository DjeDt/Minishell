/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:02:42 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/19 15:02:45 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/stat.h>
# include <signal.h>

# define ENV_USAGE "usage: env [-i] [name=value]... [utility [argument...]]"
# define SETENV_USAGE "usage: setenv [NAME=value]"
# define UNSETENV_USAGE "usage: unsetenv [NAME]"
# define CD_USAGE "usage: cd [path]"

# define FLAG_0 (0)
# define FLAG_1 (1 << 0)
# define FLAG_2 (1 << 1)

typedef struct	s_builtin
{
	const char	*ft;
	int			(*func)(const char **);
}				t_builtin;

char			**g_env;

void			get_environ(void);
char			*get_var_name(char *str);
char			*get_var_value(const char *tf);

void			bin_error(const char *str);
void			malloc_error(char *str, int ret);
int				arg_error(char *str, char *usage, char c);
int				dir_error(const char *error, const char *file);

int				ft_echo(const char **input);
int				ft_env(const char **input);
int				ft_setenv(const char **input);
int				ft_unsetenv(const char **input);
int				ft_exit(const char **input);
int				ft_cd(const char **input);

int				read_line(const int fd, char **line);
int				ft_launch_prog(const char **av);

void			get_signal(int signal);
void			print_prompt(void);
void			print_launch(void);

#endif

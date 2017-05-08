/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/05/05 17:38:39 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_builtins(const char *input)
{
	int			count;
	char		**tmp;
	s_builtin	builtin[6] = {
		{"env", &ft_env},
		{"setenv", &ft_setenv},
		{"unsetenv", &ft_unsetenv},
		{"echo", &ft_echo},
		{"cd", &ft_cd},
		{"exit", &ft_exit}
	};

	fprintf(file, "\nFonction check builtin :\n");

	count = -1;

	fprintf(file, "- struct builtin  = %p\n", builtin);

	if ((tmp = ft_split_whitespaces((char*)input)) == NULL)
		return (-1);

	fprintf(file, "- char **tmp = %p\n", tmp);

	while ((tmp[0]) && (++count < 6))
	{
		if (ft_strcmp(builtin[count].ft, tmp[0]) == 0)
		{
			(*(builtin[count].func))((const char **)tmp);
			/* LEAKS SUR TMP */
			ft_array_free(&tmp);
			return (0);
		}
	}
	if (tmp[0] != NULL)
		ft_launch_prog(tmp);
//	tmp[0] != NULL ? ft_launch_prog(tmp) : NULL;
	/* LEAKS SUR TMP */
	ft_array_free(&tmp);
	return (0);
}

static void	core(void)
{
	int		count;
	char	*line;
	char	**cmd;

	while (1)
	{
		fprintf(file, "\n/* --- START --- */\n");
		count = 0;
		ft_putstrlen("$> ");
		get_next_line(0, &line);

		fprintf(file, "input : %s\n\n", line);
		fprintf(file, "Fonction core :\n");
		fprintf(file, "- char *line = %p\n", line);

		/* LEAKS SUR CMD */
		cmd = ft_strsplit(line, ';');
		ft_memdel((void*)&line);

		fprintf(file, "- char **cmd = %p\n", cmd);

		while (cmd[count] != NULL)
			check_builtins(cmd[count++]);
		ft_array_free(&cmd);

		fprintf(file, "/* --- END --- */\n");
	}
}

int			main(void)
{
	file = fopen(LOG_P_DEB, "w+");
	get_environ();
	core();
	fclose(file);
	ft_array_free(&g_env);
	return (0);
}

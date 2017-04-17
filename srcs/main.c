/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:39:54 by ddinaut           #+#    #+#             */
/*   Updated: 2017/04/07 16:06:11 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_check_input(char **input, char **env)
{
	int		count;
	s_builtin	builtin[6] ={
		{"env", &ft_env},
		{"setenv", &ft_setenv},
		{"unsetenv", &ft_unsetenv},
		{"echo", &ft_echo},
		{"cd", NULL},
		{"exit", NULL}
	};

	count = -1;
	if (input[0] == NULL)
		return ;
	while (++count < 6)
	{
		if (ft_strcmp(builtin[count].ft, input[0]) == 0)
		{
			(*(builtin[count].func))(input, &env);
			return ;
		}
	}
	ft_getprog(input);
}

/*
static void print_list(t_env **list)
{
	t_env *tmp;
	int i;

	tmp = (*list);
	i = 0;
	while (tmp->next != NULL)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
		i++;
	}
	ft_putnbr(i);
}
*/

static int list_len(t_env **list)
{
	int i;
	t_env *tmp;

	i = -1;
	tmp = (*list);
	while (tmp->next != NULL && ++i)
		tmp = tmp->next;
	return (i);
}
static char **list_to_array(t_env **list)
{
	int count;
	char **ret;
	t_env *tmp;

	count = -1;
	ret = (char**)malloc(sizeof(char*) * list_len(list));
	tmp = (*list);
	while (tmp->next != NULL)
	{
		ret[++count] = ft_strdup(tmp->name);
		tmp = tmp->next;
	}
	ret[++count] = NULL;
	return (ret);
}

int		main(void)
{
	char		*cmd;
	char		**input;
	t_env		*struct_env;

	struct_env = NULL;
	ft_env_to_lst(&struct_env);
	while (1)
	{
		ft_putstrlen("$> ");
		get_next_line(0, &cmd);
		input = ft_split_whitespaces(cmd);
		ft_check_input(input, list_to_array(&struct_env));
		ft_memdel((void*)&cmd);
	}
	ft_arrayfree(&input);
	return (0);
}

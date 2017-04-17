#include "minishell.h"

void	list_print(t_env **list)
{
	t_env *tmp;

	tmp = (*list);
	while (tmp->next != NULL)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
	free(tmp);
}

int		list_len(t_env **list)
{
	int		count;
	t_env	*tmp;

	count = -1;
	tmp = (*list);
	while (tmp->next != NULL && ++count)
		tmp = tmp->next;
	free(tmp);
	return (count);
}

char	**list_to_array(t_env **list)
{
	int		count;
	char	**ret;
	t_env	*tmp;

	count = -1;
	if (!(ret = (char**)malloc(sizeof(char*) * list_len(list))))
		return (NULL);
	tmp = (*list);
	while (tmp->next != NULL)
	{
		ret[++count] = ft_strdup(tmp->name);
		tmp = tmp->next;
	}
	ret[++count] = NULL;
	free(tmp);
	return (ret);
}

t_env	*array_to_list(char **ar)
{
	int		count;
	t_env	*list;

	count = -1;
	list = NULL;
	if (ar != NULL)
	{
		while (ar[++count] != NULL)
			ft_add_lst_env(ar[count], ft_strlen(ar[count]), &list);
	}
	return (list);
}

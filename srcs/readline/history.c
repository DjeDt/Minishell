/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:44:33 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/06 21:46:00 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

t_hist		*create_hist(const char *str, int cur)
{
	t_hist	*ret;

	if (!(ret = (t_hist*)malloc(sizeof(t_hist))))
		return (NULL);
	if (str != NULL)
	{
		ret->cur = cur;
		ret->value = ft_strdup(str);
	}
	else
	{
		ret->value = NULL;
		ret->cur = 0;
	}
	ret->next = NULL;
	return (ret);
}

void		add_hist(const char *str, int cur, t_hist **hist)
{
	t_hist	*tmp;

	tmp = NULL;
	if (!(*hist))
		(*hist) = create_hist(str, cur);
	else
	{
		tmp = (*hist);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = create_hist(str, cur);
	}
}

void		init_hist(t_info *info)
{
	int		cur;
	int		ret;
	char	*tmp;

	cur = 0;
	ret = 1;
	tmp = NULL;
	while (ret == 1)
	{
		ret = get_next_line(info->fd, &tmp);
		add_hist(tmp, cur, &info->hist);
		ft_strdel(&tmp);
		cur++;
	}
}

int			count_hist(t_hist **hist)
{
	int		count;
	t_hist	*tmp;

	count = 0;
	tmp = *hist;
	while (tmp->next != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

static void	put_in_buf(const char *str, t_info *info)
{
	go_to_begin(info);
	ft_putstr("\033[K");
	ft_bzero(info->buf, info->buf_max_size);
	while (str[info->cur_pos] != '\0')
	{
		info->buf[info->cur_pos] = str[info->cur_pos];
		ft_putchar(info->buf[info->cur_pos]);
		info->cur_pos++;
	}
	ft_putstr(str);
}

int			history_up(t_info *info, t_hist **hist)
{
	t_hist	*tmp;

	tmp = *hist;
	if (info->cur_hist == 0)
		return (-1);
	while (tmp->next != NULL)
		tmp = tmp->next;
	put_in_buf(tmp->value, info);
	info->cur_hist -=1;
	return (0);
}

int			history_down(t_info *info, t_hist **hist)
{
	int		count;
	t_hist	*tmp;

	count = -1;
	tmp = *hist;
	while (tmp->next != NULL && ++count < info->cur_hist)
		tmp = tmp->next;
	if (tmp->value != NULL)
		put_in_buf(tmp->value, info);
	return (0);
}

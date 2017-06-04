/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:06:36 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/04 15:07:03 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void		which_key(int fd, t_info *info)
{
	read(fd, &info->c, 1);
	if (info->c == '[')
	{
		read(fd, &info->c, 1);
		if (info->c == 'C')
			arrow_right(info);
		else if (info->c == 'D')
			arrow_left(info);
		else if (info->c == 'H')
			go_to_begin(info);
		else if (info->c == 'F')
			go_to_end(info);
		else if (info->c == '3')
		{
			read(fd, &info->c, 1);
			if (info->c == '~')
				key_delete_rev(info);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:02:42 by ddinaut           #+#    #+#             */
/*   Updated: 2017/06/04 19:39:39 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include "minishell.h"
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>

typedef struct	s_info
{
	char		c;
	char		*buf;
	int			buf_size;
	int			nbr_mlc;
	int			cur_pos;
	int			buf_max_size;
	int			max_nbr_line;
	int			current_line;
	int			min_line;
	int			max_line;
}				t_info;

int				read_line(const int fd, char **line);

int				change_term_mode(void);
int				raw_mode(struct termios *prev);
int				normal_mode(struct termios *prev);

void			which_key(int fd, t_info *info);

int				arrow_left(t_info *info);
int				arrow_right(t_info *info);
void			go_to_end(t_info *info);
void			go_to_begin(t_info *info);

void			key_delete(t_info *info);
void			key_delete_rev(t_info *info);
void			add_char(t_info *info);

#endif

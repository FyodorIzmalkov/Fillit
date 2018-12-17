/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:29:34 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/17 17:02:09 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include "libft.h"

# define MAX_BUFF 547

typedef	struct		s_tetr
{
	short	x[4];
	short	y[4];
	short	height;
	short	width;
	char	symbol;
}					t_tetr;

typedef	struct		s_map
{
	char	**map;
	short	size;
}					t_map;

short				ft_get_size(short q);
void				ft_error(void);
int					ft_read_file(char *file);
void				ft_make_arr(char *buf, short q);
void				ft_validate(char **arr, short q);
short				ft_check_connection(char *str, short j);
void				ft_validate_more(char **arr, short q);
void				ft_fill_struct(char **arr, short q);
t_tetr				ft_get_coords(char *str, short i);
void				ft_get_params(t_tetr *tetr);
void				ft_free(char ***str, short q);
char				**ft_make_map(short size);
int					ft_solve_map(t_tetr tetr[], t_map mapa, short q, short i);
int					ft_is_safe(t_tetr tetr, t_map mapa, short j, short k);
void				ft_print_map(t_map mapa);
void				ft_fill_space(t_tetr tetr, t_map mapa, short j, short k);
void				ft_back_track(t_tetr tetr, t_map mapa, short j, short k);

#endif

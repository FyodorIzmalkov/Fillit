/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:29:34 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/15 19:38:34 by lsandor-         ###   ########.fr       */
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

typedef	struct	s_tetr
{
	int	x[4];
	int y[4];
	int height;
	int width;
	char	symbol;
}	t_tetr;

typedef	struct	s_map
{
	char **map;
	short size;
}	t_map;

short	ft_get_size(int q);
void	ft_error(void);
int	ft_read_file(char *file);
void	ft_make_arr(char *buf, int q);
void	ft_validate(char **arr, int q);
int		ft_check_connection(char *str, int j);
void	ft_validate_more(char **arr, int q);
void	ft_fill_struct(char **arr, int q);
t_tetr	ft_get_coords(char *str, short i);
void	ft_get_params(t_tetr *tetr);
void	ft_free(char ***str, int q);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:29:34 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/14 22:48:21 by lsandor-         ###   ########.fr       */
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

void	ft_error(void);
int	ft_read_tetr(char *file);
void	ft_make_arr(char *buf, int q);
typedef	struct	s_tetr
{
	int	x[4];
	int y[4];
	int height;
	int width;
	char	letter;
}	t_tetr;

#endif

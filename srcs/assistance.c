/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:20:35 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/17 16:56:33 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free(char ***str, short q)
{
	short i;

	i = -1;
	while (++i < q)
	{
		free(str[0][i]);
		str[0][i] = NULL;
	}
	free(str[0]);
	str[0] = NULL;
}

short	ft_get_size(short q)
{
	short res;

	res = 1;
	while ((res * res) < q)
		res++;
	return (res);
}

char	**ft_make_map(short size)
{
	short	i;
	char	**str;

	i = -1;
	if (!(str = (char**)malloc(sizeof(char*) * size)))
		ft_error();
	while (++i < size)
	{
		if (!(str[i] = ft_strnew(size)))
			ft_error();
		ft_memset(str[i], '.', size);
	}
	return (str);
}

void	ft_fill_space(t_tetr tetr, t_map mapa, short j, short k)
{
	short i;

	i = -1;
	while (++i < 4)
		mapa.map[j + tetr.y[i]][k + tetr.x[i]] = tetr.symbol;
}

void	ft_back_track(t_tetr tetr, t_map mapa, short j, short k)
{
	short i;

	i = -1;
	while (++i < 4)
		mapa.map[j + tetr.y[i]][k + tetr.x[i]] = '.';
}

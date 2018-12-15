/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:34:31 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/15 19:43:24 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void	ft_get_params(t_tetr *tetr)
{
	int max[2];
	int min[2];
	int i;

	i = 4;
	max[0] = tetr->x[0];
	max[1] = tetr->y[0];
	min[0] = tetr->x[0];
	min[1] = tetr->y[0];
	while (i--)
	{
		max[0] = (tetr->x[i] > max[0]) ? tetr->x[i] : max[0];
		max[1] = (tetr->y[i] > max[1]) ? tetr->y[i] : max[1];
		min[0] = (tetr->x[i] < min[0]) ? tetr->x[i] : min[0];
		min[1] = (tetr->y[i] < min[1]) ? tetr->y[i] : min[1];
	}
	tetr->width = max[0] - min[0] + 1;
	tetr->height = max[1] - min[1] + 1;
	i = 4;
	while (i--)
	{
		tetr->x[i] = tetr->x[i] - min[0];
		tetr->y[i] = tetr->y[i] - min[1];
	}
}


t_tetr	ft_get_coords(char *str, short i)
{
	t_tetr tetr;
	short j;
	short k;

	j = -1;
	k = 0;
	while (str[++j] != '\0')
	{
		if (str[j] == '#')
		{
			tetr.x[k] = j % 5;
			tetr.y[k] = j / 5;
			k++;
		}
	}
	tetr.symbol = i + 'A';
	ft_get_params(&tetr);
	return (tetr);
}

void	ft_fill_struct(char **arr, int q)
{
	t_tetr tetr[q];
	short i;
	t_map mapa;

	i = -1;
	while (++i < q)
		tetr[i] = ft_get_coords(arr[i], i);
	ft_free(&arr, q);
	mapa.size = ft_get_size(q * 4);
}

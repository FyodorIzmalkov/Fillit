/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:20:35 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/15 19:41:14 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free(char ***str, int q)
{
	int i;

	i = -1;
	while (++i < q)
	{
		free(str[0][i]);
		str[0][i] = NULL;
	}
	free(str[0]);
	str[0] = NULL;
}

short	ft_get_size(int q)
{
	short res;

	res = 1;
	while ((int)(res * res) < q)
		res++;
	return (res);
}

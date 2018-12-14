/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:32:37 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/14 22:49:09 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

int	ft_read_tetr(char *file)
{
	int fd;
	char	buf[MAX_BUFF];
	int len;
	int quantity;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error();
	len = 0;
	len = read(fd, buf, MAX_BUFF);
	if (len == 547)
		ft_error();
	buf[len] = '\0';
	quantity = (len + 1) / 21;
	ft_make_arr(buf, quantity);
	return (1);
}

void	ft_make_arr(char *buf, int q)
{
	int i;
	char *temp;
	char **arr;

	i = -1;
	if (!(temp = ft_strdup(buf)))
		ft_error();
	if (!(arr = (char**)malloc(q * sizeof(char*))))
		ft_error();
	while (++i < q)
	{
		if (!(arr[i] = ft_strnew(21)))
			ft_error();
		arr[i] = ft_strncpy(arr[i], temp, 21);
		if (!(temp = ft_strdup(temp + 21)))
			ft_error();
	}
	for (int i = 0; i < q; i++)
		printf("%s", arr[i]);
}

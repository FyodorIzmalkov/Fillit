/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsandor- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:32:37 by lsandor-          #+#    #+#             */
/*   Updated: 2018/12/15 19:08:48 by lsandor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read_file(char *file)
{
	int		fd;
	char	buf[MAX_BUFF];
	int		len;
	int		quantity;

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
	int				i;
	char			*temp;
	char			**arr;
	unsigned short	len;

	i = -1;
	len = 0;
	if (!(temp = ft_strdup(buf)))
		ft_error();
	if (!(arr = (char**)malloc(q * sizeof(char*))))
		ft_error();
	while (++i < q)
	{
		if (!(arr[i] = ft_strnew(21)))
			ft_error();
		arr[i] = ft_strncpy(arr[i], temp, 21);
		len += 21;
		ft_strdel(&temp);
		if (!(temp = ft_strdup(buf + len)))
			ft_error();
	}
	ft_strdel(&temp);
	ft_validate(arr, q);
}

void	ft_validate(char **arr, int q)
{
	unsigned short i[4];

	i[0] = -1;
	while (++i[0] < q)
	{
		i[1] = -1;
		i[2] = 0;
		i[3] = 0;
		while (arr[i[0]][++i[1]] != '\0')
		{
			if ((i[1] + 1) % 5 == 0)
				if (arr[i[0]][i[1]] != '\n')
					ft_error();
			if (arr[i[0]][i[1]] == '#')
				i[2]++;
			if (arr[i[0]][i[1]] == '.')
				i[3]++;
		}
		if (i[2] != 4 || i[3] != 12)
			ft_error();
	}
	ft_validate_more(arr, q);
}

void	ft_validate_more(char **arr, int q)
{
	int i;
	int j;
	int temp;
	int result;

	i = -1;
	while (++i < q)
	{
		j = -1;
		result = 0;
		while (arr[i][++j] != '\0')
		{
			temp = 0;
			if (arr[i][j] == '#')
				temp = ft_check_connection(arr[i], j);
			result += temp;
		}
		if (result < 6)
			ft_error();
	}
	ft_fill_struct(arr, q);
}

int	ft_check_connection(char *str, int j)
{
	int connect;

	connect = 0;
	if (((j + 1) <= 20) && str[j + 1] == '#')
		connect++;
	if (((j - 1) >= 0) && str[j - 1] == '#')
		connect++;
	if (((j + 5) <= 20) && str[j + 5] == '#')
		connect++;
	if (((j - 5) >= 0) && str[j - 5] == '#')
		connect++;
	return (connect);
}

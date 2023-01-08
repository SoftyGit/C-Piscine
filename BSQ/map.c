/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 00:09:42 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/15 04:58:01 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	ft_min(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b < c)
			return (b);
		else
			return (c);
	}
}

void	operate_map(int **data, int *value, int *row_col)
{
	int	i;
	int	j;

	i = 1;
	while (i < row_col[0])
	{
		j = 1;
		while (j < row_col[1])
		{
			if (data[i][j] == 1)
			{
				data[i][j] = ft_min(data[i - 1][j - 1],
						data[i][j - 1], data[i - 1][j]) + 1;
				if (data[i][j] > value[0])
				{
					value[0] = data[i][j];
					value[1] = j;
					value[2] = i;
				}
			}
			j++;
		}
		i++;
	}
}

void	draw_map(int **data, int *value)
{
	int	i;
	int	j;
	int	size;

	size = data[value[2]][value[1]];
	i = value[2];
	while (i > value[2] - size)
	{
		j = value[1];
		while (j > value[1] - size)
		{
			data[i][j] = -1;
			j--;
		}
		i--;
	}
}

void	print_map(int **data, int *row_col, char *sep)
{
	int		i;
	int		j;

	i = 0;
	while (i < row_col[0])
	{
		j = 0;
		while (j < row_col[1])
		{
			if (data[i][j] > 0)
				write(1, sep, 1);
			else if (data[i][j] < 0)
				write(1, sep + 2, 1);
			else
				write(1, sep + 1, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

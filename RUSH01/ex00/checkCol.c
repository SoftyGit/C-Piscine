/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkCol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:39:12 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/04 18:14:31 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pretty.h"

int	check_up_col(int header, int *data, int (*base)[10], int size)
{
	int	max;
	int	i;
	int	count;

	i = size - 1;
	count = 0;
	max = data[header - size * (size - 1)];
	while (i >= 0)
	{
		if (max <= data[header - (size * i)])
		{
			count++;
			max = data[header - (size * i)];
		}
		i--;
	}
	if (base[0][header % size] != count)
		return (0);
	return (1);
}

int	check_down_col(int header, int *data, int (*base)[10], int size)
{
	int	max;
	int	i;
	int	count;

	i = 0;
	count = 0;
	max = data[header];
	while (i <= size - 1)
	{
		if (max <= data[header - (size * i)])
		{
			count++;
			max = data[header - (size * i)];
		}
		i++;
	}
	if (base[1][header % size] != count)
		return (0);
	return (1);
}

int	earlycheck_up_col(int header, int *data, int (*base)[10], int size)
{
	int	max;
	int	i;
	int	count;

	i = header / size;
	count = 0;
	max = data[header - size * i];
	while (i >= 0)
	{
		if (max <= data[header - (size * i)])
		{
			count++;
			max = data[header - (size * i)];
		}
		i--;
	}
	if (base[0][header % size] < count)
		return (0);
	return (1);
}

int	earlycheck_down_col(int header, int *data, int (*base)[10], int size)
{
	int	max;
	int	i;
	int	count;

	i = 0;
	count = 0;
	max = data[header];
	while (i <= header / 4)
	{
		if (max <= data[header - (size * i)])
		{
			count++;
			max = data[header - (size * i)];
		}
		i++;
	}
	if (base[1][header % size] > count + (size - header / size - 1))
		return (0);
	return (1);
}

int	earlycheck_col(int header, int *data, int (*base)[10], int size)
{
	int	up;
	int	down;

	up = earlycheck_up_col(header, data, base, size);
	down = earlycheck_down_col(header, data, base, size);
	return (up && down);
}

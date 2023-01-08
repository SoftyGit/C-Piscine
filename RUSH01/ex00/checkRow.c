/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkRow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:39:20 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/04 18:14:29 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pretty.h"

int	check_left_row(int header, int *data, int (*base)[10], int size)
{
	int	max;
	int	i;
	int	count;

	i = size - 1;
	count = 0;
	max = data[header - size + 1];
	while (i >= 0)
	{
		if (max <= data[header - i])
		{
			count++;
			max = data[header - i];
		}
		i--;
	}
	if (base[2][header / size] != count)
		return (0);
	return (1);
}

int	check_right_row(int header, int *data, int (*base)[10], int size)
{
	int	max;
	int	i;
	int	count;

	i = 0;
	count = 0;
	max = data[header];
	while (i <= size - 1)
	{
		if (max <= data[header - i])
		{
			count++;
			max = data[header - i];
		}
		i++;
	}
	if (base[3][header / size] != count)
		return (0);
	return (1);
}

int	earlycheck_left_row(int header, int *data, int (*base)[10], int size)
{
	int	max;
	int	i;
	int	count;

	i = header % size;
	count = 0;
	max = data[header - i];
	while (i >= 0)
	{
		if (max <= data[header - i])
		{
			count++;
			max = data[header - i];
		}
		i--;
	}
	if (base[2][header / size] < count)
		return (0);
	return (1);
}

int	earlycheck_right_row(int header, int *data, int (*base)[10], int size)
{
	int	max;
	int	i;
	int	count;

	i = 0;
	count = 0;
	max = data[header];
	while (i <= header % size)
	{
		if (max <= data[header - i])
		{
			count++;
			max = data[header - i];
		}
		i++;
	}
	if (base[3][header / size] > count + (size - header % size - 1))
		return (0);
	return (1);
}

int	earlycheck_row(int header, int *data, int (*base)[10], int size)
{
	int	left;
	int	right;

	left = earlycheck_left_row(header, data, base, size);
	right = earlycheck_right_row(header, data, base, size);
	return (left && right);
}

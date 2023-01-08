/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:38:57 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/04 18:14:34 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pretty.h"

int	check_row(int header, int *data, int (*base)[10], int size)
{
	int	left;
	int	right;

	left = check_left_row(header, data, base, size);
	right = check_right_row(header, data, base, size);
	return (left && right);
}

int	check_col(int header, int *data, int (*base)[10], int size)
{
	int	up;
	int	down;

	up = check_up_col(header, data, base, size);
	down = check_down_col(header, data, base, size);
	return (up && down);
}

int	check_value(int header, int *data, int (*base)[10], int size)
{
	int	i;

	if (data[header] == 0)
		return (0);
	i = 1;
	while (header - (i * size) >= 0)
	{
		if (data[header] == data[header - ((i++) * size)])
			return (0);
	}
	i = 1;
	while ((header % size) - i >= 0)
	{
		if (data[header] == data[header - i++])
			return (0);
	}
	if (header == size * size -1)
		return (check_row(header, data, base, size)
			&& check_col(header, data, base, size));
	else if (header % size == size - 1)
		return (check_row(header, data, base, size));
	else if (header >= size * (size - 1))
		return (check_col(header, data, base, size));
	return (earlycheck_col(header, data, base, size)
		&& earlycheck_row(header, data, base, size));
}

void	operate(int *data, int num, int size, int (*base)[10])
{
	while (data[num] <= size)
	{
		if (data[100] == -1)
			break ;
		else if (check_value(num, data, base, size) && data[101] == 0)
		{
			if (num == (size * size) - 1)
				data[100] = -1;
			else
				operate(data, num + 1, size, base);
		}
		else
		{
			if (data[num] == size && num != 0)
			{
				data[num] = 0;
				data[101] = 1;
				break ;
			}
			data[num]++;
			data[101] = 0;
		}
	}
}

void	print_data(int *data, int size)
{
	int		i;
	char	str_data;

	i = 0;
	while (i < size * size)
	{
		str_data = data[i] + '0';
		write(1, &str_data, 1);
		if (i % size == size - 1)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}

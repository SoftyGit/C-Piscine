/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:29:27 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/06 14:30:12 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_value(char *data, int num)
{
	int	i;

	i = num - 1;
	if (data[0] == '1' && data[1] == '4' && data[2] == '6')
		i = num - 1;
	if (data[num] == '0' - 1)
		return (0);
	while (i >= 0)
	{
		if (data[num] == data[i--])
			return (0);
	}
	i = num - 1;
	while (i >= 0)
	{
		if (num - i == data[num] - data[i] || num - i == data[i] - data[num])
			return (0);
		i--;
	}
	return (1);
}

void	operate_extra(char *data, int *count, int num)
{
	write(1, data, 10);
	write(1, "\n", 1);
	count[0]++;
	if ((data[num] == '9') && num != 0)
	{
		data[num] = '0' - 1;
		data[11] = '1';
	}
	data[num]++;
}

void	operate(char *data, int *count, int num)
{
	while (data[num] <= '9')
	{
		if (check_value(data, num) && data[11] == '0')
		{
			if (num == 9)
			{
				operate_extra(data, count, num);
				break ;
			}
			else
				operate(data, count, num + 1);
		}
		else
		{
			if ((data[num] == '9') && num != 0)
			{
				data[num] = '0' - 1;
				data[11] = '1';
				break ;
			}
			data[num]++;
			data[11] = '0';
		}
	}
}

void	init(char *data)
{
	int	i;

	i = 0;
	while (i < 12)
		data[i++] = '0' - 1;
}

int	ft_ten_queens_puzzle(void)
{
	char	data[12];
	int		count[1];

	count[0] = 0;
	init(data);
	operate(data, count, 0);
	return (count[0]);
}

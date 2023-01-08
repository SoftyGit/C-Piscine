/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:53:14 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/14 15:58:48 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

long	ft_atoi(char *str)
{
	int		i;
	long	point[2];

	i = 0;
	point[0] = 1;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			point[0] *= -1;
	point[1] = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		point[1] *= 10;
		point[1] += str[i++] - '0';
	}
	return ((int)(point[1] * point[0]));
}

void	ft_putnbr(long value)
{
	char	temp;

	if (value < 0)
	{
		write(1, "-", 1);
		value *= -1;
	}
	if (value < 10)
	{
		temp = value + '0';
		write(1, &temp, 1);
		return ;
	}
	ft_putnbr(value / 10);
	temp = value % 10 + '0';
	write(1, &temp, 1);
}

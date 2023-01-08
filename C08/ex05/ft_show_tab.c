/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:24:34 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/12 14:37:32 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

int	ft_strlen2(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	ft_putnbr(int value)
{
	char	temp;

	if (value < 10)
	{
		temp = value + '0';
		write(1, &temp, 1);
	}
	else
	{
		temp = value % 10 + '0';
		ft_putnbr(value / 10);
		write(1, &temp, 1);
	}
}

void	ft_show_tab(t_stock_str *par)
{
	int		i;

	i = 0;
	while (par[i].str != 0)
	{
		write(1, par[i].str, ft_strlen2(par[i].str));
		write(1, "\n", 1);
		if (par[i].size == 0)
			write(1, "0", 1);
		else
			ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, ft_strlen2(par[i].copy));
		write(1, "\n", 1);
		i++;
	}
}

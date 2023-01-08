/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:46:34 by yongjale          #+#    #+#             */
/*   Updated: 2022/08/27 14:58:54 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_repeat(int nb)
{
	char	a;
	char	b;

	b = '-';
	if (nb < 0)
	{
		nb *= -1;
		write(1, &b, 1);
		ft_putnbr_repeat(nb);
	}
	else if (nb > 0)
	{
		a = (nb % 10) + 48;
		ft_putnbr_repeat(nb / 10);
		write(1, &a, 1);
	}
}

void	ft_putnbr(int nb)
{
	char	a;
	char	b;

	b = '-';
	if (nb == 0)
	{
		write(1, "0", 1);
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		nb *= -1;
		write(1, &b, 1);
		ft_putnbr_repeat(nb);
	}
	else if (nb > 0)
	{
		a = (nb % 10) + 48;
		ft_putnbr_repeat(nb / 10);
		write(1, &a, 1);
	}
}

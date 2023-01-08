/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:24:23 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/05 20:15:04 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_pretty_strlen(char *base)
{
	int	i;
	int	check[300];

	i = 0;
	if (base[0] == 0 || base[1] == 0)
		return (-1);
	while (i < 300)
		check[i++] = 0;
	i = 0;
	while (i < 300 && base[i] != 0)
	{
		if (check[(int)base[i]] == 1 || base[i] == '+' || base[i] == '-')
			return (-1);
		else
			check[(int)base[i]] = 1;
		i++;
	}
	return (i);
}

void	ft_pretty_division(int nbr, int length, char *base)
{
	if (nbr == 0)
		return ;
	ft_pretty_division(nbr / length, length, base);
	write(1, base + (nbr) % length, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		length;
	long	temp;

	temp = 2147483648;
	length = ft_pretty_strlen(base);
	if (length == -1)
		return ;
	if (nbr == 0)
		write(1, base, 1);
	else if (nbr > 0)
		ft_pretty_division(nbr, length, base);
	else if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_pretty_division((int)(temp / length), length, base);
		write(1, base + (int)(temp % length), 1);
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		ft_pretty_division(nbr, length, base);
	}	
}

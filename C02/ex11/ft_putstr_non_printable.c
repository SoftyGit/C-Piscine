/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:57:20 by yongjale          #+#    #+#             */
/*   Updated: 2022/08/31 13:54:20 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_are_you_non_print(char *str, int i)
{
	if ((unsigned char)str[i] < 32 || (unsigned char)str[i] >= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	ft_pretty_print(int value)
{
	int	temp;

	if (value < 10)
	{
		temp = value + 48;
		write(1, &temp, 1);
	}
	else
	{
		temp = value + 87;
		write(1, &temp, 1);
	}
}

void	ft_pretty_16(char *str, int i)
{
	int		q;
	int		r;

	q = ((unsigned char)str[i]) / 16;
	r = ((unsigned char)str[i]) % 16;
	write(1, "\\", 1);
	ft_pretty_print(q);
	ft_pretty_print(r);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (!ft_are_you_non_print(str, i))
		{
			write(1, str + i, 1);
		}
		else
		{
			ft_pretty_16(str, i);
		}
		i++;
	}
}

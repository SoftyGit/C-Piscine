/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:16:05 by yongjale          #+#    #+#             */
/*   Updated: 2022/08/25 21:21:18 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_pretty_help(int n, int static_max, char *a)
{
	int		i;

	i = 1;
	while (n + i <= static_max)
	{
		a[n + i] = a[n + i -1] + 1;
		i++;
	}
}

void	ft_pretty_print(int n, int static_max, char *a, int *check)
{
	if (n == static_max - 1)
	{
		while (a[n] <= '9')
		{
			if (check[0] != 0)
			{
				write(1, a + 10, 2);
			}
			write(1, a, static_max);
			check[0] = 1;
			a[n]++;
		}
	}
	else
	{
		while (a[n] <= '9')
		{
			ft_pretty_print(n + 1, static_max, a, check);
			a[n]++;
			ft_pretty_help(n, static_max, a);
		}
	}
}

void	ft_init(char *a)
{
	int		i;

	i = 8;
	while (i > -1)
	{
		a[i] = 48 + i;
		i--;
	}
	a[10] = ',';
	a[11] = ' ';
}

void	ft_print_combn(int n)
{
	char	a[13];
	int		check[2];

	check[0] = 0;
	ft_init(a);
	ft_pretty_print(0, n, a, check);
}

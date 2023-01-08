/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:29:24 by yongjale          #+#    #+#             */
/*   Updated: 2022/08/25 14:45:36 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_extra(char *a, int *check)
{
	a[5] = a[2];
	a[6] = a[3] + 1;
	while (a[5] <= '9')
	{
		while (a[6] <= '9')
		{
			if (check[0] == 0)
			{
				write(1, a + 2, 5);
				check[0] = 1;
			}
			else
			{
				write(1, a, 7);
			}
			a[6]++;
		}
		a[5]++;
		a[6] -= 10;
	}
	a[3]++;
}

void	ft_print_comb2(void)
{
	int		check[1];
	char	a[8];

	a[0] = ',';
	a[1] = ' ';
	a[2] = '0';
	a[3] = '0';
	a[4] = ' ';
	a[5] = '0';
	a[6] = '1';
	check[0] = 0;
	while (a[2] <= '9')
	{
		while (a[3] <= '9')
		{
			ft_print_extra(a, check);
		}
		a[2]++;
		a[3] -= 10;
	}
}

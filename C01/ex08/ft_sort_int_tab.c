/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:34:04 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/08/26 15:42:11 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_pretty_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	repeat;
	int	i;

	repeat = 0;
	while (repeat < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_pretty_swap(&tab[i], &tab[i + 1]);
			}
			i++;
		}
		repeat++;
	}
}

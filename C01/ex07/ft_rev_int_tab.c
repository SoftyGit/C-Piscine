/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fearingsoft <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:20:49 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/08/26 15:33:16 by fearingsoft      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_new_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	count;

	count = 0;
	while (count < size / 2)
	{
		ft_new_swap(&tab[count], &tab[size - count - 1]);
		count++;
	}
}

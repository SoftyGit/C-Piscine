/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 01:27:12 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/09/14 16:11:46 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	ft_intcmp(int a1, int a2)
{
	if (a1 > a2)
		return (a1 - a2);
	else if (a1 < a2)
		return (a1 - a2);
	else
		return (0);
}
*/

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	check[2];

	i = 0;
	check[0] = 0;
	check[1] = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			check[0] = 1;
		else if (f(tab[i], tab[i + 1]) < 0)
			check[1] = 1;
		i++;
	}
	if (check[0] && check[1] == 1)
		return (0);
	else
		return (1);
}

/*
#include <stdio.h>
int main()
{
	int tab[10] = {1,2,3,4,5,5,7,8,9,10};	
	//int tab[10] = {9,9,8,7,6,5,4,3,2,2};	
	printf("%d",ft_is_sort(tab, 10, ft_intcmp));
}
*/

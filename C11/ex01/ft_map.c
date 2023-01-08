/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 01:08:47 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/09/14 15:26:08 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*value;

	i = 0;
	value = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		value[i] = f(tab[i]);
		i++;
	}
	return (value);
}

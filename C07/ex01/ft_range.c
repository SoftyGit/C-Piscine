/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 23:46:16 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/07 15:09:15 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*new;

	if (min >= max)
		return (0);
	new = (int *)malloc((sizeof(int) * (max - min)));
	if (new == NULL)
		return (0);
	i = 0;
	while (i < max - min)
	{
		new[i] = min + i;
		i++;
	}
	return (new);
}

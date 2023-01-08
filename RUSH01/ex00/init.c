/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:39:27 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/04 18:14:28 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pretty.h"

void	init_data(int *data)
{
	int	i;	

	i = 0;
	while (i < 102)
		data[i++] = 0;
}

void	init_base(int (*base)[10], char *argv, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			base[i][j] = argv[2 * (i * size + j)] - '0';
			j++;
		}
		i++;
	}
}

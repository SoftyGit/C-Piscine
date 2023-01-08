/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:06:49 by juykim            #+#    #+#             */
/*   Updated: 2022/09/15 04:44:55 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	free_str_array(char **arr, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free((arr)[i]);
		++i;
	}
	free(arr);
}

void	free_array(int **arr, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free((arr)[i]);
		++i;
	}
	free(arr);
}

int	**error_free(char **str)
{
	free(*str);
	write(1, "map error\n", 10);
	exit(0);
}

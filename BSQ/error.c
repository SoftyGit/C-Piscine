/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:47:31 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/15 04:42:27 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	map_error_free_one(char *src)
{
	free(src);
	write(1, "map error\n", 10);
	exit(0);
}

void	map_error_free_two(char **arr, int row)
{
	int	i;

	i = 0;
	while (i <= row)
	{
		free((arr)[i]);
		++i;
	}
	free(arr);
	write(1, "map error\n", 10);
	exit(0);
}

void	map_error_free_int_two(int **arr, int row)
{
	int	i;

	i = 0;
	while (i <= row)
	{
		free((arr)[i]);
		++i;
	}
	free(arr);
	write(1, "map error\n", 10);
	exit(0);
}

void	map_error_free_three(char *src, int **arr, int row)
{
	int	i;

	i = 0;
	free(src);
	while (i <= row)
	{
		free((arr)[i]);
		++i;
	}
	free(arr);
	write(1, "map error\n", 10);
	exit(0);
}

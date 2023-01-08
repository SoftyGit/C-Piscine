/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:30:44 by juykim            #+#    #+#             */
/*   Updated: 2022/09/15 04:45:10 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	pretty_lines(int **arr, int *row_col, int *value)
{
	int	i;

	i = 0;
	while (i < row_col[0])
	{
		if (arr[i][0] > value[0])
		{
			value[0] = arr[i][0];
			value[1] = 0;
			value[2] = i;
		}
		i++;
	}
	i = 0;
	while (i < row_col[1])
	{
		if (arr[0][i] > value[0])
		{
			value[0] = arr[0][i];
			value[1] = i;
			value[2] = 0;
		}
		i++;
	}
}

void	pretty_print(int **arr, int *row_col, char *sep)
{
	int	value[3];

	value[0] = -1;
	value[1] = -1;
	value[2] = -1;
	pretty_lines(arr, row_col, value);
	operate_map(arr, value, row_col);
	if (value[1] == 0 && arr[0][0] == 0)
	{
		write(1, "map error\n", 10);
		return ;
	}
	draw_map(arr, value);
	print_map(arr, row_col, sep);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		row_col[2];
	char	sep[3];
	int		**arr;

	i = 1;
	if (argc == 1)
	{	
		write_map();
	}
	while (i < argc)
	{
		arr = set_array(argv[i], row_col, sep);
		if (!arr)
		{
			write(1, "map error\n", 10);
			free_array(arr, row_col[0]);
			++i;
			continue ;
		}
		pretty_print(arr, row_col, sep);
		free_array(arr, row_col[0]);
		++i;
	}
	return (0);
}

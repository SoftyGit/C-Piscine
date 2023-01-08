/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_make_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:59:00 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/15 04:50:12 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	make_configure(char *buffer, int *row_col, char *sep)
{
	int	i;
	int	j;

	i = 0;
	row_col[0] = 0;
	while (buffer[i] >= '0' && buffer[i] <= '9' && i < ft_strlen(buffer) - 4)
	{
		row_col[0] *= 10;
		row_col[0] += buffer[i] - '0';
		i++;
	}
	if (i == 0 || row_col[0] == 0)
		map_error_free_one(buffer);
	j = 0;
	while (j < 3)
	{
		if (buffer[i] == 0)
			map_error_free_one(buffer);
		sep[j] = buffer[i];
		i++;
		j++;
	}
	if (buffer[i] != 10)
		map_error_free_one(buffer);
}

void	make_check(char *buffer, char *sep)
{
	if (sep[0] == sep[1])
		map_error_free_one(buffer);
	else if (sep[0] == sep[2])
		map_error_free_one(buffer);
	else if (sep[1] == sep[2])
		map_error_free_one(buffer);
}

void	make_col(int *row_col, char *data)
{
	int	i;

	i = 0;
	while (data[i] != 10)
		i++;
	row_col[1] = i;
}

char	**make_input(int *row_col, char *sep)
{
	char	*buffer;
	char	**data;
	int		i;

	buffer = (char *)malloc(sizeof(char) * 20);
	read(0, buffer, 20);
	make_configure(buffer, row_col, sep);
	make_check(buffer, sep);
	i = 0;
	data = (char **)malloc(sizeof(char *) * row_col[0]);
	while (i < row_col[0])
	{
		data[i] = (char *)malloc(sizeof(char) * 10000);
		read(0, data[i], 10000);
		if (i == 0)
			make_col(row_col, *data);
		else if (data[i][row_col[1]] != 10)
		{
			free(buffer);
			map_error_free_two(data, i);
		}
		i++;
	}
	free(buffer);
	return (data);
}

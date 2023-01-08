/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:05:44 by juykim            #+#    #+#             */
/*   Updated: 2022/09/15 04:57:37 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*dest != 0)
		++dest;
	while (*src != 0)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = 0;
	return (tmp);
}

int	**write_to_int_map(int *row_col, char **data, char *sep)
{
	int	i;
	int	j;
	int	**value;

	value = (int **)malloc(sizeof(int *) * row_col[0]);
	i = 0;
	while (i < row_col[0])
	{
		j = 0;
		value[i] = (int *)malloc(sizeof(int) * row_col[1]);
		while (j < row_col[1])
		{
			if (data[i][j] == sep[0])
				value[i][j] = 1;
			else if (data[i][j] == sep[1])
				value[i][j] = 0;
			else
				map_error_free_int_two(value, j);
			j++;
		}
		i++;
	}
	return (value);
}

void	write_map(void)
{
	int		**data;
	int		row_col[2];
	char	sep[3];
	char	**temp;

	temp = make_input(row_col, sep);
	data = write_to_int_map(row_col, temp, sep);
	pretty_print(data, row_col, sep);
	free_str_array(temp, row_col[0]);
	free_array(data, row_col[0]);
}

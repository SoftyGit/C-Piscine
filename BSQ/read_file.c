/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:26:55 by juykim            #+#    #+#             */
/*   Updated: 2022/09/15 04:45:20 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	**allocate_array(int row, int col)
{
	int	**arr;
	int	i;

	arr = (int **)malloc(row * sizeof(int *));
	if (!(arr))
		return (0);
	i = -1;
	while (++i < row)
	{
		arr[i] = (int *)malloc(col * sizeof(int));
		if (!(arr[i]))
			return (0);
	}
	return (arr);
}

int	valid_char(char c, char empty, char obstacle)
{
	if (c == empty)
		return (1);
	if (c == obstacle)
		return (0);
	return (-2);
}

int	**build_array(char *str, int row, int col, char *sep)
{
	int		i;
	int		j;
	int		**arr;
	char	*temp;

	temp = str;
	arr = allocate_array(row, col);
	if (!(arr))
		return (0);
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (valid_char(*str, sep[0], sep[1]) == -2)
				map_error_free_int_two(arr, row - 1);
			arr[i][j] = valid_char(*str, sep[0], sep[1]);
			++str;
		}
		if (*str != '\n')
			return (0);
		++str;
	}
	return (arr);
}

char	*read_file(char *argv)
{
	int		fd;
	int		length;
	char	*str;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{	
		exit(1);
		return (0);
	}
	str = (char *)malloc(1500000000 * sizeof(char));
	if (!str)
		return (0);
	length = read(fd, str, 1500000000);
	close(fd);
	return (str);
}

int	**set_array(char *argv, int *row_col, char *sep)
{
	char	*str;
	int		**arr;
	int		init_len;
	int		error;

	str = read_file(argv);
	if (!str)
		return (0);
	init_len = define_condition(str);
	if (init_len < 4)
		error_free(&str);
	error = define_char(str, init_len, sep, row_col);
	if (error == -1)
		error_free(&str);
	row_col[1] = define_column(str);
	arr = build_array(str + init_len + 1, row_col[0], row_col[1], sep);
	free(str);
	return (arr);
}

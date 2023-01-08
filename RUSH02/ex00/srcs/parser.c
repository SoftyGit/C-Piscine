/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunk <hyunjunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:52:02 by hyunjunk          #+#    #+#             */
/*   Updated: 2022/09/11 21:57:26 by hyunjunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

t_dict	*parse_dict_file(const char	*fname)
{
	t_dict			*dict_arr;
	t_dict			*dict_arr_p;
	const int		fd = open(fname, O_RDONLY);

	if (fd == -1)
		return (dict_error_ret_null());
	dict_arr = (t_dict *)malloc((get_dict_count(fname) + 1) * sizeof(t_dict));
	dict_arr_p = dict_arr;
	dict_arr_p = parse_dict_cat(dict_arr_p, fd);
	if (dict_arr_p == NULLPTR)
		return (dict_arr);
	dict_arr_p->key = NULLPTR;
	close(fd);
	return (dict_arr);
}

void	free_dict(t_dict	*arr)
{
	int	i;

	i = 0;
	while (arr[i].key != NULLPTR)
	{
		free((void *)arr[i].key);
		free((void *)arr[i].value);
		i++;
	}
	free(arr);
}

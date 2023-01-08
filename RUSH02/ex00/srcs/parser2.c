/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunk <hyunjunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:58:48 by hyunjunk          #+#    #+#             */
/*   Updated: 2022/09/11 21:38:12 by hyunjunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

t_dict	*parse_dict_cat(t_dict *arr, int fd)
{
	int		ret;
	char	buff[1024];

	while (TRUE)
	{
		ret = get_key(fd, buff);
		if (ret == -1)
			break ;
		if (ret == 0)
			return (dict_error_ret_null());
		arr->key = ft_strdup(buff);
		ret = get_value(fd, buff);
		if (ret == 0)
			return (dict_error_ret_null());
		arr->value = ft_strdup(buff);
		arr++;
	}
	return (arr);
}

int	get_key(int fd, char	*buff)
{
	int	i;

	i = 0;
	while (read(fd, &buff[i], sizeof(char)))
	{
		if (my_is_space(buff[i]) == TRUE)
			continue ;
		if (buff[i] == '\n')
			continue ;
		if (buff[i] == ':')
		{
			buff[i] = '\0';
			return (i);
		}
		if (buff[i] < '0' || '9' < buff[i] || buff[i] == '\n')
			return (0);
		i++;
	}
	return (-1);
}

int	get_value(int fd, char	*buff)
{
	int	i;

	i = 0;
	while (read(fd, &buff[i], sizeof(char)))
	{
		if (my_is_space(buff[i]) == TRUE)
			continue ;
		if (buff[i] == '\n')
			break ;
		if ((buff[i] < 'a' || 'z' < buff[i])
			&& ((buff[i] < 'A' || 'Z' < buff[i])))
			return (0);
		i++;
	}
	buff[i] = '\0';
	return (i);
}

int	get_dict_count(const char	*fname)
{
	const int	fd = open(fname, O_RDONLY);
	int			dict_i;
	int			ret;
	char		buff[1024];

	if (fd == -1)
		return (-1);
	dict_i = 0;
	while (TRUE)
	{
		ret = get_key(fd, buff);
		if (ret == -1)
			break ;
		if (ret == 0)
			return (-1);
		ret = get_value(fd, buff);
		if (ret == 0)
			return (-1);
		dict_i++;
	}
	close(fd);
	return (dict_i);
}

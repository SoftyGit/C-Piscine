/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 23:03:28 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/09/13 16:56:41 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_count(char *str, char *charset, int *count)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = -1;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (charset[j] == str[i])
			{
				if (str[i + 1] == 0)
					count[1]++;
				if (i == 0 || i - check == 1)
					count[1]++;
				count[0]++;
				check = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_record(char *str, char *charset, int *data)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 1;
	data[0] = -1;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (charset[j] == str[i])
				data[num++] = i;
			j++;
		}
		i++;
	}
	data[num++] = ft_strlen(str) + 1;
	data[num] = -2;
}

void	ft_make(char *str, char **value, int *data)
{
	int	i;
	int	j;
	int	k;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (data[i + 1] != -2)
	{
		if (data[i + 1] - data[i] != 1)
		{
			j = data[i] + 1;
			k = 0;
			value[count++] = (char *)malloc(sizeof(char)
					* (data[i + 1] - data[i]));
			while (j < data[i + 1])
			{
				value[count - 1][k++] = str[j];
				j++;
			}
			value[count - 1][k] = 0;
		}
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**value;
	int		*data;
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	ft_count(str, charset, count);
	value = (char **)malloc(sizeof(char *) * (count[0] - count[1] + 2));
	data = (int *)malloc(sizeof(int) * (count[0] + 3));
	ft_record(str, charset, data);
	ft_make(str, value, data);
	value[count[0] - count[1] + 1] = NULL;
	return (value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:16:42 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/10 21:25:02 by yongjale         ###   ########.fr       */
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

void	ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != 0)
		i++;
	j = 0;
	while (src[j] != 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
}

void	ft_strjoin_extra(int num, char *data, char **strs, char *sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < num)
	{
		if (i != 0)
		{
			ft_strcat(data, sep);
		}
		ft_strcat(data, strs[j]);
		i++;
		j++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		sum;
	char	*data;

	if (size <= 0)
	{
		data = (char *)malloc(sizeof(char) * 1);
		data[0] = 0;
		return (data);
	}
	i = 0;
	sum = 0;
	while (i < size)
		sum += ft_strlen(strs[i++]);
	sum = sum + ft_strlen(sep) * (size - 1) + 1;
	data = (char *)malloc(sizeof(char) * sum);
	data[0] = 0;
	ft_strjoin_extra(size, data, strs, sep);
	data[sum - 1] = 0;
	return (data);
}

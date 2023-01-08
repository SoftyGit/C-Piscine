/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:55:13 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/09/12 13:07:38 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(src))
	{
		new[i] = src[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*data;

	data = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (data == NULL)
		return (0);
	i = 0;
	while (i < ac)
	{
		data[i].str = av[i];
		data[i].copy = ft_strdup(av[i]);
		data[i].size = ft_strlen(av[i]);
		i++;
	}
	data[i].str = 0;
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 23:27:07 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/07 13:52:37 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

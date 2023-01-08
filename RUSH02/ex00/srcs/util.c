/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunk <hyunjunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:35:47 by hyunjunk          #+#    #+#             */
/*   Updated: 2022/09/11 20:46:55 by hyunjunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include <stdlib.h>

int	my_is_space(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\v'
		|| ch == '\f' || ch == '\r')
		return (1);
	return (0);
}

char	*ft_strdup(char	*src)
{
	char	*ret;
	char	*p;
	int		src_len;

	if (src == NULLPTR)
		return (NULLPTR);
	p = src;
	while (*p != '\0')
		p++;
	src_len = p - src;
	ret = (char *)malloc((src_len + 1) * sizeof(char));
	p = ret;
	while (*src != '\0')
		*p++ = *src++;
	*p = '\0';
	return (ret);
}

int	ft_strlen(char	*str)
{
	char	*p;

	p = str;
	while (*p != '\0')
	{
		p++;
	}
	return (p - str);
}

int	ft_strcmp(char *s1, char	*s2)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while (*u_s1 == *u_s2)
	{
		if (*u_s1 == '\0')
		{
			return (0);
		}
		u_s1++;
		u_s2++;
	}
	return (*u_s1 - *u_s2);
}

int	strlen_only_number(char	*str)
{
	char	*p;

	p = str;
	while (*p != '\0')
	{
		if (*p < '0' || '9' < *p)
		{
			return ((int)dict_error_ret_null());
		}
		p++;
	}
	return (p - str);
}

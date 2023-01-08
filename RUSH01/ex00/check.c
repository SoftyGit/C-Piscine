/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:39:06 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/04 18:14:32 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pretty.h"

int	check_argv_value(int len, char *argv)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (argv[2 * i] > len / 4 + '0')
			return (0);
		i++;
	}
	return (1);
}

int	check_argv(int argc, char *argv)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (argc != 2)
		return (-1);
	while (argv[i])
	{
		if (argv[i] < '1' || argv[i] > '9')
			return (-1);
		len++;
		if (argv[i + 1] == '\0')
			break ;
		else if (argv[i + 1] != ' ')
			return (-1);
		i += 2;
	}
	if (len >= 16 && len <= 36 && len % 4 == 0)
		if (check_argv_value(len, argv))
			return (len / 4);
	return (-1);
}

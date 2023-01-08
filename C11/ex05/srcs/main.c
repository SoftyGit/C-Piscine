/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:02:34 by fearingsoft       #+#    #+#             */
/*   Updated: 2022/09/14 16:08:09 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <unistd.h>

int	doop(int a, int b, int *check, char **argv)
{
	int	i;
	int	(*op[5])(int, int, int *);

	op[0] = sum;
	op[1] = sub;
	op[2] = mul;
	op[3] = div;
	op[4] = mod;
	i = 0;
	if (ft_strcmp(argv[2], "+") == 1)
		i = 0;
	else if (ft_strcmp(argv[2], "-") == 1)
		i = 1;
	else if (ft_strcmp(argv[2], "*") == 1)
		i = 2;
	else if (ft_strcmp(argv[2], "/") == 1)
		i = 3;
	else if (ft_strcmp(argv[2], "%") == 1)
		i = 4;
	else
		return (0);
	return (op[i](a, b, check));
}

int	main(int argc, char **argv)
{
	int	check;
	int	value;

	check = 0;
	if (argc != 4)
		return (0);
	value = doop(ft_atoi(argv[1]), ft_atoi(argv[3]), &check, argv);
	if (check == 1)
		return (0);
	ft_putnbr((long)value);
	write(1, "\n", 1);
	return (0);
}

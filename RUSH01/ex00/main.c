/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:39:33 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/04 18:14:27 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pretty.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	data[102];
	int	base[4][10];
	int	size;

	size = check_argv(argc, argv[1]);
	if (size == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_data(data);
	init_base(base, argv[1], size);
	operate(data, 0, size, base);
	if (data[0] == size + 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print_data(data, size);
	return (0);
}

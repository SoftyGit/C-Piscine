/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjale <yongjale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:43:10 by yongjale          #+#    #+#             */
/*   Updated: 2022/09/14 15:58:50 by yongjale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <unistd.h>

int	sum(int a, int b, int *check)
{
	*check = 0;
	return (a + b);
}

int	sub(int a, int b, int *check)
{
	*check = 0;
	return (a - b);
}

int	mul(int a, int b, int *check)
{
	*check = 0;
	return (a * b);
}

int	div(int a, int b, int *check)
{
	if (b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		*check = 1;
		return (0);
	}
	*check = 0;
	return (a / b);
}

int	mod(int a, int b, int *check)
{
	if (b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		*check = 1;
		return (0);
	}
	*check = 0;
	return (a % b);
}

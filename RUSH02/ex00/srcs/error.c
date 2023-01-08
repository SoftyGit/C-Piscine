/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunk <hyunjunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:00:16 by hyunjunk          #+#    #+#             */
/*   Updated: 2022/09/11 17:21:51 by hyunjunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include <unistd.h>

int	argc_error(void)
{
	const char	msg[] = "Error\n";

	write(STDOUT, msg, sizeof(msg) - 1);
	return (-1);
}

void	*dict_error_ret_null(void)
{
	const char	msg[] = "Dict Error\n";

	write(STDOUT, msg, sizeof(msg) - 1);
	return (NULLPTR);
}
